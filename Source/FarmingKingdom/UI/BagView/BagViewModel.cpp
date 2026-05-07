// Fill out your copyright notice in the Description page of Project Settings.


#include "BagViewModel.h"
#include "BagDataMgr.h"
#include "BagItemData.h"
//PRAGMA_DISABLE_OPTIMIZATION
void UBagViewModel::PostInitProperties()
{
	Super::PostInitProperties();
}
void UBagViewModel::InitData()
{
	UBagDataMgr* BagDataMgr = GetGameInstanceSubsystem<UBagDataMgr>();
	if (BagDataMgr)
	{
		TMap<FGameplayTag, int32> BagData;
		BagDataMgr->GetRunTimeBagData(BagData);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BagDataMgr is null."));
	}

	//UBagItemData* ItemData = nullptr;
}
//PRAGMA_ENABLE_OPTIMIZATION