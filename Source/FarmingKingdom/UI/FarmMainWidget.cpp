// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmMainWidget.h"

#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"

//PRAGMA_DISABLE_OPTIMIZATION

void UFarmMainWidget::OnInit()
{
	Super::OnInit();
}

void UFarmMainWidget::OnShow()
{
	Super::OnShow();
}

void UFarmMainWidget::OnHide()
{
	Super::OnHide();
}

void UFarmMainWidget::OnRecycle()
{
	Super::OnRecycle();
}

void UFarmMainWidget::BindWidgetModel(UFarmUIBaseModel* InWidgetModel)
{
	Super::BindWidgetModel(InWidgetModel);
	if (WidgetModel != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("FarmMainWidget bind widget model"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FarmMainWidget bind widget model is null"));
	}
}

void UFarmMainWidget::UnBindWidgetModel()
{
	Super::UnBindWidgetModel();
}

//PRAGMA_ENABLE_OPTIMIZATION