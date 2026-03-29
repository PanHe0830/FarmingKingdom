// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmUIManagerSubsystem.h"

#include "Blueprint/UserWidget.h"
#include "FarmMainViewMode.h"
#include "FarmMainWidget.h"
#include "FarmUIBaseWidget.h"

void UFarmUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    CurrentState = EUIState::None;
}

void UFarmUIManagerSubsystem::Deinitialize()
{
    TArray<FName> Keys;
    WidgetMap.GetKeys(Keys);
    for (const FName& UIName : Keys)
    {
        RecycleUI(UIName);
    }

    CurrentState = EUIState::Invalid;

    Super::Deinitialize();
}

UFarmUIBaseWidget* UFarmUIManagerSubsystem::CreateUI(FName UIName, TSubclassOf<UFarmUIBaseWidget> WidgetClass)
{
    if (!WidgetClass)
    {
        return nullptr;
    }

    if (TObjectPtr<UFarmUIBaseWidget>* FoundWidget = WidgetMap.Find(UIName))
    {
        return FoundWidget->Get();
    }

    if (UWorld* World = GetWorld())
    {
        UFarmUIBaseWidget* NewWidget = CreateWidget<UFarmUIBaseWidget>(World, WidgetClass);
        if (!NewWidget)
        {
            return nullptr;
        }

        WidgetMap.Add(UIName, NewWidget);
        return NewWidget;
    }

    return nullptr;
}

bool UFarmUIManagerSubsystem::ShowUI(FName UIName, int32 ZOrder)
{
    TObjectPtr<UFarmUIBaseWidget>* FoundWidget = WidgetMap.Find(UIName);
    if (!FoundWidget || !::IsValid(FoundWidget->Get()))
    {
        return false;
    }

    UFarmUIBaseWidget* Widget = FoundWidget->Get();
    if (!Widget->IsInViewport())
    {
        Widget->AddToViewport(ZOrder);
    }
    Widget->OnShow();
    return true;
}

bool UFarmUIManagerSubsystem::HideUI(FName UIName)
{
    TObjectPtr<UFarmUIBaseWidget>* FoundWidget = WidgetMap.Find(UIName);
    if (!FoundWidget || !::IsValid(FoundWidget->Get()))
    {
        return false;
    }

    FoundWidget->Get()->OnHide();
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

