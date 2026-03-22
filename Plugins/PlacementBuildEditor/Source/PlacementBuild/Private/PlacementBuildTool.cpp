// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementBuildTool.h"

PlacementBuildTool::PlacementBuildTool()
{
}

PlacementBuildTool::~PlacementBuildTool()
{
    World = nullptr;
}

void PlacementBuildTool::Initialize(UWorld* InWorld)
{
    World = InWorld;
}

FBuildRuntimeBuildResult PlacementBuildTool::GetRuntimeBuildResult(const FBuildRuntimeClickedContext& ClickedContext)
{
	UE_LOG(LogTemp, Warning, TEXT("GetRuntimeBuildResult"));

	FBuildRuntimeBuildResult BuildResult;
	BuildResult.isSuccess = false;

	if (!World)
	{
		return BuildResult;
	}

	//--------------------------------------
	// 1. 基础数据
	//--------------------------------------
	const FVector HalfExtent = ClickedContext.BuildBound.BoxExtent;

	const FVector SurfaceNormal =
		ClickedContext.HitResult.ImpactNormal.GetSafeNormal();

	const FVector ImpactPoint =
		ClickedContext.HitResult.ImpactPoint;

	constexpr float PlacementEpsilon = 0.5f; // 稍微加大一点更稳定

	//--------------------------------------
	// 2. 获取被点击物体的尺寸
	//--------------------------------------
	FVector HitHalfExtent = FVector::ZeroVector;

	if (const UPrimitiveComponent* HitComp = ClickedContext.HitResult.GetComponent())
	{
		HitHalfExtent = HitComp->Bounds.BoxExtent;
	}

	//--------------------------------------
	// 3. 计算沿法线方向的“厚度”
	//--------------------------------------
	const float NewExtentAlongNormal =
		FMath::Abs(FVector::DotProduct(HalfExtent, SurfaceNormal));

	const float HitExtentAlongNormal =
		FMath::Abs(FVector::DotProduct(HitHalfExtent, SurfaceNormal));

	//--------------------------------------
	// 4. 计算最终位置
	//--------------------------------------
	const FVector CandidateLocation =
		ImpactPoint +
		SurfaceNormal * (NewExtentAlongNormal + HitExtentAlongNormal + PlacementEpsilon);

	//--------------------------------------
	// 5. 计算旋转（关键升级点）
	//--------------------------------------
	// 让物体Z轴对齐法线
	const FQuat AlignQuat =
		FQuat::FindBetweenNormals(FVector::UpVector, SurfaceNormal);

	//--------------------------------------
	// 6. 最终Transform
	//--------------------------------------
	const FTransform CandidateTransform(AlignQuat, CandidateLocation);
	BuildResult.FinalTransform = CandidateTransform;

	//--------------------------------------
	// 7. 碰撞检测（使用旋转后的OBB）
	//--------------------------------------
	FCollisionShape CollisionShape =
		FCollisionShape::MakeBox(HalfExtent);

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;

	// 忽略点击对象
	if (ClickedContext.HitResult.GetComponent())
	{
		QueryParams.AddIgnoredComponent(ClickedContext.HitResult.GetComponent());
	}

	if (ClickedContext.HitResult.GetActor())
	{
		QueryParams.AddIgnoredActor(ClickedContext.HitResult.GetActor());
	}

	// 忽略外部传入
	QueryParams.AddIgnoredActors(ClickedContext.IgnoreActors);

	for (UStaticMeshComponent* Comp : ClickedContext.IgnoreStaticMeshComponent)
	{
		if (Comp)
		{
			QueryParams.AddIgnoredComponent(Comp);
		}
	}

	//--------------------------------------
	// 8. 多通道检测（重要升级）
	//--------------------------------------
	bool bBlocked = false;

	// 静态物体
	bBlocked |= World->OverlapBlockingTestByChannel(
		CandidateLocation,
		AlignQuat,
		ECC_WorldStatic,
		CollisionShape,
		QueryParams
	);

	// 动态物体
	bBlocked |= World->OverlapBlockingTestByChannel(
		CandidateLocation,
		AlignQuat,
		ECC_WorldDynamic,
		CollisionShape,
		QueryParams
	);

	//--------------------------------------
	// 9. 结果
	//--------------------------------------
	if (bBlocked)
	{
		BuildResult.isSuccess = false;
		return BuildResult;
	}

	BuildResult.isSuccess = true;
	return BuildResult;
}