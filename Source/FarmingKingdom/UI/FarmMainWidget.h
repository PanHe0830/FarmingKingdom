// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FarmUIBaseWidget.h"
#include "FarmMainWidget.generated.h"

class UButton;
class UFarmMainViewMode;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmMainWidget : public UFarmUIBaseWidget
{
	GENERATED_BODY()

    void OnInit() override;

    void OnShow() override;

    void OnHide() override;

    void OnRecycle() override;

public:
	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	//UButton* TextButton;

    UFUNCTION(BlueprintCallable, Category = "MVVM")
    void SetupViewModel(UFarmMainViewMode* InViewModel);
};