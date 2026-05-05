// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "BagDataMgr.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagDataMgr : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	void InitBagData();

public:
	void SaveBagData();

private:
	UPROPERTY()
	TMap<FGameplayTag, int32> RunTimeBagData;

	const FString SlotName = TEXT("BagSlot");
	const int32 UserIndex = 0;
};
