// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include <GameplayTagContainer.h>
#include "BagItemData.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagItemData : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite)
    TObjectPtr<UTexture2D> Icon;

    UPROPERTY(BlueprintReadWrite)
    FText ItemText;

	UPROPERTY(BlueprintReadWrite)
	FGameplayTag ItemTag;
};
