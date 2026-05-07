// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../FarmUIBaseModel.h"
#include "BagViewModel.generated.h"

class UBagItemData;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagViewModel : public UFarmUIBaseModel
{
	GENERATED_BODY()

protected:
	void PostInitProperties() override;

private:
	UPROPERTY()
	TArray<UBagItemData*> BagItemList;
};
