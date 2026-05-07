// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmUIManagerSubsystem.h"
#include "FarmUIBaseModel.h"

#include "Blueprint/UserWidget.h"
#include "FarmMainWidget.h"
#include "FarmUIBaseWidget.h"
#include "UIConfigRow.h"
#include "Engine/World.h"

void UFarmUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    CurrentState = EUIState::None;

    LoadUIConfig();
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
		UIModelMap.Add(Row->UIId, Row->ViewModelClass);
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

    for (auto& item : UIModelMap)
    {
        if (item.Value)
        {
            item.Value = nullptr;
        }
    }
    UIModelMap.Empty();
    
    for (auto& Elem : WidgetMap)
    {
        if (Elem.Value)
        {
            Elem.Value->UnBindWidgetModel();
            Elem.Value->RemoveFromParent();
			Elem.Value = nullptr;
        }
	}
    WidgetMap.Empty();

    CurrentState = EUIState::Invalid;

    Super::Deinitialize();
}

void UFarmUIManagerSubsystem::CreateUI(FName UIName, TSoftClassPtr<UFarmUIBaseWidget> WidgetClass)
{
    if (WidgetMap.Contains(UIName))
    {
        return;
    }

    if (WidgetClass.IsNull())
    {
        UE_LOG(LogTemp, Warning, TEXT("WidgetClass for UI %s is not valid"), *UIName.ToString());
        return;
    }

    UClass* FoundModelClass = UIModelMap.Find(UIName)->Get();
    if (!FoundModelClass || !FoundModelClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("Model for UI %s is not valid"), *UIName.ToString());
        return;
    }

    UClass* LoadedClass = WidgetClass.LoadSynchronous();

    UWorld* World = GetWorld();

    if (!World || !LoadedClass)
        return;

    UFarmUIBaseWidget* Widget = CreateWidget<UFarmUIBaseWidget>(World, LoadedClass);
    UFarmUIBaseModel* Model = NewObject<UFarmUIBaseModel>(GetGameInstance(), FoundModelClass);

    if (Widget && Model)
    {
        Model->InitData();
        Widget->BindWidgetModel(Model);
        WidgetMap.Add(UIName, Widget);
    }
}

bool UFarmUIManagerSubsystem::ShowUI(FName UIName, int32 ZOrder)
{
    auto* FoundWidget = WidgetMap.Find(UIName);
    if (FoundWidget != nullptr)
    {
        UFarmUIBaseWidget* widget = FoundWidget->Get();
        if (widget != nullptr)
        {
			widget->OnShow();
        }
        else
        {
			return false;
        }
    }
    else
    {
		return false;
    }
    
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
        return ShowUI(TEXT("MainWidget"), 0);
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

    // 先清理UI
    for (auto& Elem : WidgetMap)
    {
        if (Elem.Value)
        {
            Elem.Value->RemoveFromParent();
        }
    }
    WidgetMap.Empty();

    // 重新创建UI
    for (auto& Elem : UIClassMap)
    {
        CreateUI(Elem.Key, Elem.Value);
    }

	//UE_LOG(LogTemp, Warning, TEXT("UI Manager Subsystem: World Begin Play, UI reloaded"));
    // 进入到最后的UI状态
    EnterState(CurrentState);
}