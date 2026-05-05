// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../FarmUIBaseWidget.h"
#include "GameplayTagContainer.h"
#include "BagView.generated.h"

class UBagItemView;
class UTileView;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagView : public UFarmUIBaseWidget
{
	GENERATED_BODY()
public:
	void OnInit() override;

	void OnShow() override;

	void OnHide() override;

	void OnRecycle() override;

	void BindWidgetModel(UFarmUIBaseModel* InWidgetModel) override;

	void UnBindWidgetModel() override;

private:
	void InitBagItemView();

	UPROPERTY()
	TMap<FGameplayTag , UBagItemView*> WidgetModelMap;

public:
	UPROPERTY(meta = (BindWidget))
	UTileView* TileView;
};
