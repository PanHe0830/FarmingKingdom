// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIConfig.h"
#include "UIConfigRow.generated.h"


USTRUCT(BlueprintType)
struct FUIConfigRow : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName UIId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EUIState UIType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftClassPtr<UUserWidget> WidgetClass;
};
