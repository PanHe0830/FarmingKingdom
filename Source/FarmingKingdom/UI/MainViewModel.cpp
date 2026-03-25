// Fill out your copyright notice in the Description page of Project Settings.


#include "MainViewModel.h"
#include <Components/Button.h>
#include <Components/Image.h>

void UMainViewModel::OnButtonClicked()
{
    UE_LOG(LogTemp , Warning , TEXT("OnButtonClicked"));
    // 改颜色
    ButtonColor = FLinearColor::Red;

    // 输出时间
    FString TimeStr = FDateTime::Now().ToString();
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TimeStr);

    UE_MVVM_SET_PROPERTY_VALUE(ButtonColor, ButtonColor);
}