// Fill out your copyright notice in the Description page of Project Settings.


#include "BagItemView.h"

#include <Components/TextBlock.h>
#include <Components/Image.h>

void UBagItemView::SetItemImage(UTexture2D* Image)
{
	ItemImage->SetBrushFromTexture(Image);
}

void UBagItemView::SetItemText(const FText& Text)
{
	ItemTextBlock->SetText(Text);
}
