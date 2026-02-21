// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EntityConfig.generated.h"

class UCurveFloat;

/**
 * 
 */
UCLASS()
class WORLDSTATE_API UEntityConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Entity")
	UCurveFloat* EntityCurve;

	UPROPERTY(EditAnywhere, Category = "Entity")
	float EntityCurveScale = 1.f;

	UPROPERTY(EditAnywhere, Category = "Entity")
	bool bLoop = false;
};
