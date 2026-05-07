// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "BagDataMgr.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class FARMINGKINGDOM_API UBagDataMgr : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	void InitBagData();
	void InitTableConfig();

public:
	void SaveBagData();

	void GetRunTimeBagData(TMap<FGameplayTag, int32>& OutBagData) const
	{
		OutBagData = RunTimeBagData;
	}

	void GetTagIconData(FGameplayTag Tag, FName& OutIconPath) const;

private:    
	UPROPERTY(Config)
	TSoftObjectPtr<UDataTable> DT_TagIconPtr;

	UPROPERTY()
	TMap<FGameplayTag, int32> RunTimeBagData;

	UPROPERTY()
	UDataTable* DT_TagIcon;

	const FString SlotName = TEXT("BagSlot");
	const int32 UserIndex = 0;
};
