// Fill out your copyright notice in the Description page of Project Settings.


#include "BagView.h"
#include "BagItemData.h"

#include <Components/TileView.h>

void UBagView::OnInit()
{
	Super::OnInit();

	InitBagItemView();
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
