// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FarmPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API AFarmPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	
private:
	void MouseClick();

	UPROPERTY(EditAnywhere, Category = "HitSetting")
	float hitDistance = 20000.0f;
};
