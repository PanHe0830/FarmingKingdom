// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FarmUIBaseWidget.h"
#include "FarmMainWidget.generated.h"

class UButton;
class UFarmMainViewMode;
class UHorizontalBox;

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

    void BindWidgetModel(UFarmUIBaseModel* InWidgetModel) override;

    void UnBindWidgetModel() override;

public:
    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* HorizontalBox_Top;

    UPROPERTY(meta = (BindWidget))
    UHorizontalBox* HorizontalBox_Under;
};