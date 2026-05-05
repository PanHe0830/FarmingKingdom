// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../FarmUIBaseWidget.h"
#include "BagItemView.generated.h"

class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagItemView : public UFarmUIBaseWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BagItemView")
	void SetItemImage(UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "BagItemView")
	void SetItemText(const FText& Text);

	UPROPERTY(meta = (BindWidget))
	UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemTextBlock;
};
