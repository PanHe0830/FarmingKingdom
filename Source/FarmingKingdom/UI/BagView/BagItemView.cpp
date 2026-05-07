// Fill out your copyright notice in the Description page of Project Settings.


#include "BagItemView.h"
#include "BagItemData.h"

#include <Components/TextBlock.h>
#include <Components/Image.h>

void UBagItemView::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	SetCursor(EMouseCursor::Hand);
}

void UBagItemView::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	SetCursor(EMouseCursor::Default);
}

//FReply UBagItemView::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
//{
//	if (ItemData)
//	{
//		OnItemDataClicked.Broadcast(ItemData);
//	}
//
//	return FReply::Handled();
//}

void UBagItemView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	//IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	ItemData = Cast<UBagItemData>(ListItemObject);
	if (ItemData)
	{
		SetItemImage(ItemData->Icon);
		SetItemText(ItemData->ItemText);
	}
	else
	{
		SetItemImage(nullptr);
		SetItemText(FText::GetEmpty());
	}
}

void UBagItemView::SetItemImage(UTexture2D* Image)
{
	if (!Image) return;
	ItemImage->SetBrushFromTexture(Image);
}

void UBagItemView::SetItemText(const FText& Text)
{
	if (Text.IsEmpty())
	{
		ItemTextBlock->SetText(FText::GetEmpty());
	}
	else
	{
		ItemTextBlock->SetText(Text);
	}
}
