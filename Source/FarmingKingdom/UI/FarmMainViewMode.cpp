// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmMainViewMode.h"

void UFarmMainViewMode::SetGold(int32 InGold)
{
    UE_MVVM_SET_PROPERTY_VALUE(Gold, InGold);
}

void UFarmMainViewMode::SetPlayerName(const FText& InPlayerName)
{
    UE_MVVM_SET_PROPERTY_VALUE(PlayerName, InPlayerName);
}

void UFarmMainViewMode::OnMainButtonClicked()
{
    UE_MVVM_SET_PROPERTY_VALUE(MainButtonColor, FLinearColor::Red);
}
