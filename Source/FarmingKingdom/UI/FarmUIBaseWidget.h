#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FarmUIBaseWidget.generated.h"

class UMVVMViewModelBase;

UCLASS(Abstract, Blueprintable)
class FARMINGKINGDOM_API UFarmUIBaseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void OnInit();

    virtual void OnShow();

    virtual void OnHide();

    virtual void OnRecycle();
protected:
    UPROPERTY(BlueprintReadOnly, Category = "MVVM")
    TObjectPtr<UMVVMViewModelBase> currentViewModel;
};
