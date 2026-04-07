// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmUIManagerSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "FarmMainViewMode.h"
#include "FarmMainWidget.h"
#include "FarmUIBaseWidget.h"
#include "UIConfigRow.h"
#include "Engine/World.h"

void UFarmUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    CurrentState = EUIState::None;
    LoadUIConfig();
    InitAllUI();
}

void UFarmUIManagerSubsystem::LoadUIConfig()
{
    FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &UFarmUIManagerSubsystem::OnWorldBeginPlay);

    if (UIConfigTable.IsNull())
    {
        UE_LOG(LogTemp, Error, TEXT("UIConfigTable is null (check ini config)"));
        return;
    }

    UDataTable* Table = UIConfigTable.LoadSynchronous();
    if (!Table)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load UIConfigTable"));
        return;
    }
    TArray<FUIConfigRow*> Rows;
    Table->GetAllRows(TEXT("UFarmUIManagerSubsystem"), Rows);

    for (FUIConfigRow* Row : Rows)
    {
        if (!Row) continue;

        UIClassMap.Add(Row->UIId, Row->WidgetClass);
    }
}

void UFarmUIManagerSubsystem::InitAllUI()
{
    for (const auto& Pair : UIClassMap)
    {
        CreateUI(Pair.Key, Pair.Value);
	}
}

void UFarmUIManagerSubsystem::Deinitialize()
{
    UIClassMap.Empty();
    
    TArray<FName> Keys;
    WidgetMap.GetKeys(Keys);
    for (const FName& UIName : Keys)
    {
        RecycleUI(UIName);
    }

    CurrentState = EUIState::Invalid;

    Super::Deinitialize();
}

void UFarmUIManagerSubsystem::CreateUI(FName UIName, TSoftClassPtr<UFarmUIBaseWidget> WidgetClass)
{
    if (auto* FoundPtr = WidgetMap.Find(UIName))
    {
        return;
    }

    if (WidgetClass.IsNull())
    {
		UE_LOG(LogTemp, Warning, TEXT("WidgetClass for UI %s is not valid"), *UIName.ToString());
        return;
    }


    UClass* LoadedClass = WidgetClass.LoadSynchronous();
	UWorld* world = GetWorld();
    if (LoadedClass && world)
    {
        UFarmUIBaseWidget* Widget = CreateWidget<UFarmUIBaseWidget>(world, LoadedClass);
        if (Widget)
        {
            WidgetMap.Add(UIName, Widget);
			return;
        }
        else
        {
            UE_LOG(LogTemp,Warning , TEXT("CreateWidget get widget is null"));
        }
    }

    return;
}

bool UFarmUIManagerSubsystem::ShowUI(FName UIName, int32 ZOrder)
{
    UFarmUIBaseWidget* FoundWidget = *WidgetMap.Find(UIName);
    if (!FoundWidget || !::IsValid(FoundWidget))
    {
        return false;
    }

    if (!FoundWidget->IsInViewport())
    {
        FoundWidget->AddToViewport(ZOrder);
    }
    FoundWidget->OnShow();
    return true;
}

bool UFarmUIManagerSubsystem::HideUI(FName UIName)
{
    UFarmUIBaseWidget* FoundWidget = *WidgetMap.Find(UIName);
    if (!FoundWidget || !::IsValid(FoundWidget))
    {
        return false;
    }

    FoundWidget->OnHide();
    return true;
}

bool UFarmUIManagerSubsystem::RecycleUI(FName UIName)
{

    return true;
}

bool UFarmUIManagerSubsystem::ChangeUIState(EUIState NewState)
{
    if (NewState == CurrentState)
    {
        return true;
    }

    ExitState(CurrentState);
    if (!EnterState(NewState))
    {
        return false;
    }

    CurrentState = NewState;
    return true;
}

bool UFarmUIManagerSubsystem::EnterState(EUIState NewState)
{
    switch (NewState)
    {
    case EUIState::None:
        return true;
    case EUIState::MainMenu:
    {
        return ShowUI(TEXT("Main"), 0);
    }
    case EUIState::Gameplay:
    {
        return HideUI(TEXT("Main"));
    }
    case EUIState::Building:
    {
        return ShowUI(TEXT("Main"), 0);
    }
    default:
        break;
    }

    return false;
}

void UFarmUIManagerSubsystem::ExitState(EUIState OldState)
{
    switch (OldState)
    {
    case EUIState::MainMenu:
    case EUIState::Gameplay:
        HideUI(TEXT("Main"));
        break;
    case EUIState::Building:
        HideUI(TEXT("Main"));
        break;
    case EUIState::None:
    case EUIState::Invalid:
        break;
    default:
        break;
    }
}

void UFarmUIManagerSubsystem::OnWorldBeginPlay(UWorld* World, const UWorld::InitializationValues Values)
{
    if (!World || !World->IsGameWorld()) return;

    if (UIClassMap.Num() <= 0) return;
    // TODO 切换关卡了重新创建UI

    
}

