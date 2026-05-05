// Fill out your copyright notice in the Description page of Project Settings.


#include "BagItemView.h"
#include "BagItemData.h"

#include <Components/TextBlock.h>
#include <Components/Image.h>

void UBagItemView::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	//IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UBagItemData* ItemData = Cast<UBagItemData>(ListItemObject);
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
	if (Text.IsEmpty()) return;
	ItemTextBlock->SetText(Text);
}
