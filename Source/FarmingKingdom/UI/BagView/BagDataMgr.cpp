// Fill out your copyright notice in the Description page of Project Settings.


#include "BagDataMgr.h"
#include "Kismet/GameplayStatics.h"
#include "../../SaveGame/FarmSaveGame.h"

void UBagDataMgr::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	InitBagData();
}

void UBagDataMgr::InitBagData()
{
	if (UGameplayStatics::DoesSaveGameExist(SlotName, UserIndex))
	{
		UFarmSaveGame* LoadData = Cast<UFarmSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, UserIndex));

		if (LoadData)
		{
			RunTimeBagData = LoadData->BagData;
		}
		else
		{
			// 加载失败：初始化默认数据
			UE_LOG(LogTemp, Warning, TEXT("Failed to load save game data. Initializing default bag data."));
			RunTimeBagData.Empty();
		}
	}
	else
	{
		// 没存档：初始化默认数据
		UE_LOG(LogTemp, Warning, TEXT("No save game found. Initializing default bag data."));
		RunTimeBagData.Empty();
	}
}

void UBagDataMgr::SaveBagData()
{
	UFarmSaveGame* SaveObj = Cast<UFarmSaveGame>(UGameplayStatics::CreateSaveGameObject(UFarmSaveGame::StaticClass()));

	if (!SaveObj)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create save game object."));
		return;
	}

	SaveObj->BagData = RunTimeBagData;

	UGameplayStatics::SaveGameToSlot(SaveObj, SlotName, UserIndex);
}
