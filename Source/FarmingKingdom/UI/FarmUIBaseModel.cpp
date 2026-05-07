// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmUIBaseModel.h"

void UFarmUIBaseModel::PostInitProperties()
{
	Super::PostInitProperties();
}

void UFarmUIBaseModel::InitData()
{

}

void UFarmUIBaseModel::ClearData()
{

}

UGameInstance* UFarmUIBaseModel::GetGameInstance() const
{
	UObject* Outer = GetOuter();
	if (Outer)
	{
		if (UWorld* World = Outer->GetWorld())
		{
			return World->GetGameInstance();
		}
	}
	return nullptr;
}
