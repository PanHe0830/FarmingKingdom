// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FarmMainViewMode.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmMainViewMode : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "MainUI")
    int32 Gold = 0;

    UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "MainUI")
    FText PlayerName;

    UPROPERTY(BlueprintReadWrite, FieldNotify, Category = "MainUI")
    FLinearColor MainButtonColor = FLinearColor::White;

    UFUNCTION(BlueprintCallable, Category = "MainUI")
    void SetGold(int32 InGold);

    UFUNCTION(BlueprintCallable, Category = "MainUI")
    void SetPlayerName(const FText& InPlayerName);

    UFUNCTION(BlueprintCallable, Category = "MainUI")
    void OnMainButtonClicked();
};
