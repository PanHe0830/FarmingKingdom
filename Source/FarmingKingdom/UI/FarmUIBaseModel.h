// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FarmUIBaseModel.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmUIBaseModel : public UObject
{
	GENERATED_BODY()
	
protected:
	void PostInitProperties() override;

public:
	void ClearData();

	UGameInstance* GetGameInstance() const;

	template<typename T>
	T* GetGameInstanceSubsystem() const
	{
		if (UGameInstance* GI = GetGameInstance())
		{
			return GI->GetSubsystem<T>();
		}
		return nullptr;
	}
};