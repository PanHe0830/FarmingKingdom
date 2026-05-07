// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../FarmUIBaseWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "BagItemView.generated.h"

class UImage;
class UTextBlock;
class UBagItemData;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UBagItemView : public UFarmUIBaseWidget , public IUserObjectListEntry
{
	GENERATED_BODY()
	
protected:
	void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	//FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

public:
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UFUNCTION(BlueprintCallable, Category = "BagItemView")
	void SetItemImage(UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "BagItemView")
	void SetItemText(const FText& Text);

	UPROPERTY(meta = (BindWidget))
	UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemTextBlock;

	UPROPERTY()
	TObjectPtr<UBagItemData> ItemData;

	//DECLARE_MULTICAST_DELEGATE_OneParam(FOnItemClicked, UBagItemData*);
	//FOnItemClicked OnItemDataClicked;
};
