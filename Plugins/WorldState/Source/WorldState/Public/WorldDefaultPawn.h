// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "WorldDefaultPawn.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSTATE_API AWorldDefaultPawn : public ADefaultPawn
{
	GENERATED_BODY()
	
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;

protected:
	void BeginPlay() override;
};
