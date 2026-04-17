// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialShowViewModel.h"

void UMaterialShowViewModel::SetMaterialValue(FText NewValue)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(MaterialValue, NewValue))
	{
		UE_LOG(LogTemp, Log, TEXT("[PhoneHomeViewModel] 时间已更新: %s"), *NewValue.ToString());
	}
}