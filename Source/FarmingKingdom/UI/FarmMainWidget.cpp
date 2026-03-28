// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmMainWidget.h"
#include "FarmMainViewMode.h"

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

void UFarmMainWidget::SetupViewModel(UFarmMainViewMode* InViewModel)
{
    currentViewModel = InViewModel;
}
