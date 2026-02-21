// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantComponent.h"
#include "../../PlantConfig.h"
#include "UWorldStateSubsystem.h"

void UPlantComponent::UpdatePlantGrowth(float DeltaTime)
{
	if (PlantConfig || PlantConfig->EntityCurve) return;

	float curValue = PlantConfig->EntityCurve->GetFloatValue(DeltaTime);
}

void UPlantComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UWorld* World = GetWorld())
	{
		if (auto* Subsystem = World->GetGameInstance()->GetSubsystem<UUWorldStateSubsystem>())
		{
			Subsystem->RegisterComponent(this);
			currentPlantTime = Subsystem->GetWorldTime();
		}
	}

}

void UPlantComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (UWorld* World = GetWorld())
	{
		if (auto* Subsystem = World->GetGameInstance()->GetSubsystem<UUWorldStateSubsystem>())
		{
			Subsystem->UnregisterComponent(this);
		}
	}
}

void UPlantComponent::SetPlantActor(AActor* InActor)
{
	OwnerActor = InActor;
}

void UPlantComponent::ClearPlantActor()
{
	OwnerActor = nullptr;
}

void UPlantComponent::UpdateFromTime(float dealTime)
{
	float LocalTime;
	float worldTime = FMath::Max(0.f, dealTime - currentPlantTime);
	
	GrowthDuration = PlantConfig->EntityCurve->FloatCurve.GetLastKey().Time;
	if (PlantConfig->bLoop)
	{
		float Normalized = worldTime / GrowthDuration;
		float Cycle = FMath::Frac(Normalized);
		LocalTime = Cycle * GrowthDuration;
	}
	else
	{
		LocalTime = FMath::Clamp(worldTime, 0.f, GrowthDuration);
	}

	float Alpha = PlantConfig->EntityCurve->GetFloatValue(LocalTime);

	float Scale = FMath::Lerp(0.0f, 100.0f, Alpha); 
	FVector NewScale = FVector::OneVector * Scale;
	GetOwner()->SetActorScale3D(NewScale);
}
