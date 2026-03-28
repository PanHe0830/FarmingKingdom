// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FarmUIManagerSubsystem.generated.h"

class UFarmUIBaseWidget;
class UFarmMainWidget;
class UFarmMainViewMode;

UENUM(BlueprintType)
enum class EUIState : uint8
{
    Invalid ,
    None ,
    Gameplay ,
    MainMenu ,
    Building 
};

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION(BlueprintCallable, Category = "UI")
    UFarmUIBaseWidget* CreateUI(FName UIName, TSubclassOf<UFarmUIBaseWidget> WidgetClass);

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool ShowUI(FName UIName, int32 ZOrder = 0);

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool HideUI(FName UIName);

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool RecycleUI(FName UIName);

    UFUNCTION(BlueprintCallable, Category = "UI")
    bool ChangeUIState(EUIState NewState);

    UFUNCTION(BlueprintPure, Category = "UI")
    EUIState GetCurrentUIState() const { return CurrentState; }

private:
    bool EnterState(EUIState NewState);
    void ExitState(EUIState OldState);

    UPROPERTY(Transient)
    EUIState CurrentState;

    UPROPERTY(Transient)
    TMap<FName, TObjectPtr<UFarmUIBaseWidget>> WidgetMap;
};
