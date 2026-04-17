// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "MaterialShowViewModel.generated.h"

/**
 * 
 */
UCLASS()
class FARMINGKINGDOM_API UMaterialShowViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	/** 获取当前时间文本（格式：HH:MM） */
	FText GetMaterialValue() const { return MaterialValue; }

public:
	/** 设置当前时间 */
	void SetMaterialValue(FText NewValue);

protected:
	UPROPERTY(BlueprintReadWrite, FieldNotify , Setter , Getter)
	FText MaterialValue;
};
