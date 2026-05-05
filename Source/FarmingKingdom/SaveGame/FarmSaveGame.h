// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameplayTagContainer.h"
#include "FarmSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TMap<FGameplayTag, int32> BagData;
};
