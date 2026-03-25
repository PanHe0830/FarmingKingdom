// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MainViewModel.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UMainViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, FieldNotify)
    int32 Gold;
};
