// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FarmMainWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UFarmMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* TextButton;
};