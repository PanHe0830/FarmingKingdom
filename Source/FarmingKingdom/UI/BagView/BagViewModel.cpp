// Fill out your copyright notice in the Description page of Project Settings.


#include "BagViewModel.h"
#include "BagDataMgr.h"
#include "BagItemData.h"

void UBagViewModel::PostInitProperties()
{
	Super::PostInitProperties();

	UBagDataMgr* BagDataMgr = GetGameInstanceSubsystem<UBagDataMgr>();
	if (BagDataMgr)
	{
		TMap<FGameplayTag, int32> BagData;
		BagDataMgr->GetRunTimeBagData(BagData);
	}

	//UBagItemData* ItemData = nullptr;
	
}
