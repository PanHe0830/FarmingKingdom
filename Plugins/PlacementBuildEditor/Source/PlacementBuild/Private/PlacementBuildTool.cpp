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
    FBuildRuntimeBuildResult buildResult;
    buildResult.isSuccess = false;

	const FVector HalfExtent = ClickedContext.BuildBound.BoxExtent;

	const FVector SurfaceNormal = ClickedContext.HitResult.ImpactNormal.GetSafeNormal();

	constexpr float PlacementEpsilon = 0.1f;

	FVector HitHalfExtent = FVector::ZeroVector;

	if (const UPrimitiveComponent* HitComp = ClickedContext.HitResult.GetComponent())
	{
		HitHalfExtent = HitComp->Bounds.BoxExtent;
	}

	const float NewMeshExtentAlongNormal =
		HalfExtent.ProjectOnToNormal(SurfaceNormal).Size();

	const float HitMeshExtentAlongNormal =
		HitHalfExtent.ProjectOnToNormal(SurfaceNormal).Size();

	const FVector CandidateLocation =
		ClickedContext.HitResult.ImpactPoint +
		SurfaceNormal * (NewMeshExtentAlongNormal + PlacementEpsilon);

	// 设置最终位置和旋转
	buildResult.FinalTransform = FTransform(FRotator::ZeroRotator, CandidateLocation);

	FCollisionShape CollisionShape =
		FCollisionShape::MakeBox(HalfExtent);

	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;
	if (ClickedContext.HitResult.GetComponent())
	{
		QueryParams.AddIgnoredComponent(ClickedContext.HitResult.GetComponent());
		QueryParams.AddIgnoredActor(ClickedContext.HitResult.GetActor());
	}
	QueryParams.AddIgnoredActors(ClickedContext.IgnoreActors);
	for (UStaticMeshComponent* comp : ClickedContext.IgnoreStaticMeshComponent)
	{
		if (comp)
		{
			QueryParams.AddIgnoredComponent(comp);
		}
	}

	const bool bBlocked =
		World->OverlapBlockingTestByChannel(
			CandidateLocation,
			FQuat::Identity,
			ECC_WorldStatic,
			CollisionShape,
			QueryParams
		);

	if (bBlocked)
	{
		buildResult.isSuccess = false;
		return buildResult;
	}

	buildResult.isSuccess = true;
    return buildResult;
}
