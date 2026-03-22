// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "WorldDefaultPawn.generated.h"

struct FBuildRuntimeClickedContext;

/**
 * 
 */
UCLASS()
class WORLDSTATE_API AWorldDefaultPawn : public ADefaultPawn
{
	GENERATED_BODY()

	AWorldDefaultPawn();
	
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;

public:
	void MouseClick(FBuildRuntimeClickedContext& context);

protected:
	void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<class UPlacementBuildComponent> BuildComponent;
};
