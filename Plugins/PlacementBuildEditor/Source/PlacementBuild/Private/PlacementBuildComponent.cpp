// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementBuildComponent.h"
#include "PlacementResult.h"

// Sets default values for this component's properties
UPlacementBuildComponent::UPlacementBuildComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

// Called when the game starts
void UPlacementBuildComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	BuildTool = MakeUnique<PlacementBuildTool>();
	BuildTool->Initialize(GetWorld());
}


// Called every frame
void UPlacementBuildComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlacementBuildComponent::MouseClick(FBuildRuntimeClickedContext& context)
{
	if (BuildTool.IsValid())
	{
		FBuildRuntimeBuildResult result = BuildTool->GetRuntimeBuildResult(context);
		if (result.isSuccess)
		{
			// 这里直接放在组件里了，实际可以通过事件或者接口传出去
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			GetWorld()->SpawnActor<AActor>(AActor::StaticClass(), result.FinalTransform, SpawnParams);
		}
	}
}

