// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "PlantComponent.generated.h"

class UPlantConfig;
class AActor;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UPlantComponent : public UEntityComponent
{
	GENERATED_BODY()

private:
	void UpdatePlantGrowth(float DeltaTime);

	UPROPERTY(VisibleAnywhere)
	AActor* OwnerActor = nullptr;

protected:
	void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	void SetPlantActor(AActor* InActor);

	void ClearPlantActor();

	void UpdateFromTime(float dealTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Config")
	UPlantConfig* PlantConfig;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	float currentPlantTime = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	float elapsedTime = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
	float GrowthDuration = 0.0f;
};
