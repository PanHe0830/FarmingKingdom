// Fill out your copyright notice in the Description page of Project Settings.


#include "BagView.h"
#include "BagItemData.h"
#include "BagViewModel.h"

#include <Components/TileView.h>

void UBagView::OnInit()
{
	Super::OnInit();

	BagViewModel = Cast<UBagViewModel>(WidgetModel);
	if (!BagViewModel)
	{
		UE_LOG(LogTemp, Warning, TEXT("BagViewModel is null or of incorrect type."));
		return;
	}

	InitBagItemView();

	TileView->OnItemClicked().AddUObject(this,&UBagView::HandleItemClicked);
}

void UBagView::OnShow()
{
	Super::OnShow();
}

void UBagView::OnHide()
{
	Super::OnHide();
}

void UBagView::OnRecycle()
{
	Super::OnRecycle();
}

void UBagView::BindWidgetModel(UFarmUIBaseModel* InWidgetModel)
{
	Super::BindWidgetModel(InWidgetModel);
}

void UBagView::UnBindWidgetModel()
{
	Super::UnBindWidgetModel();
}

void UBagView::InitBagItemView()
{
	TArray<UBagItemData*> BagItemList;

	for (int i = 0; i < BagSlotCount; ++i)
	{
		UBagItemData* ItemData = NewObject<UBagItemData>();
		ItemData->Icon = nullptr;
		ItemData->ItemText = FText::AsNumber(i + 1);
		BagItemList.Add(ItemData);
	}

	TileView->ClearListItems();

	for (UBagItemData* ItemData : BagItemList)
	{
		TileView->AddItem(ItemData);
	}
}

void UBagView::HandleItemClicked(UObject* item)
{
	UBagItemData* ItemData = Cast<UBagItemData>(item);
	if (ItemData)
	{
		UE_LOG(LogTemp, Warning, TEXT("Clicked item: %s"), *ItemData->ItemText.ToString());
	}
}
