#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FarmUIBaseWidget.generated.h"

class UFarmUIBaseModel;

UCLASS(Abstract, Blueprintable)
class FARMINGKINGDOM_API UFarmUIBaseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void OnInit();

    virtual void OnShow();

    virtual void OnHide();

    virtual void OnRecycle();

	virtual void BindWidgetModel(UFarmUIBaseModel* InWidgetModel);

	virtual void UnBindWidgetModel();

	TSubclassOf<UFarmUIBaseModel> GetWidgetModelClass() const { return WidgetClass; }

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UFarmUIBaseModel> WidgetClass;

    UPROPERTY()
	UFarmUIBaseModel* WidgetModel;
};
