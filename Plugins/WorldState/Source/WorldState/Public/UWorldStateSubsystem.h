// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UWorldStateSubsystem.generated.h"

class FWorldTime;

/**
 * 
 */
UCLASS()
class WORLDSTATE_API UUWorldStateSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	float GetWorldTime() const;

	void RegisterComponent(class UEntityComponent* Component);

	void UnregisterComponent(UEntityComponent* Component);
	
private:
	TUniquePtr<FWorldTime> WorldTime;

	FTimerHandle TimeUpdateHandle;

	TArray<TWeakObjectPtr<class UEntityComponent>> RegisteredComponents;
};
