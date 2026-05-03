#include "FarmUIBaseWidget.h"

void UFarmUIBaseWidget::OnInit()
{

}

void UFarmUIBaseWidget::OnShow()
{
	IsInViewport() ? SetVisibility(ESlateVisibility::Visible) : AddToViewport(0);
}

void UFarmUIBaseWidget::OnHide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UFarmUIBaseWidget::OnRecycle()
{
	RemoveFromParent();
}

void UFarmUIBaseWidget::BindWidgetModel(UFarmUIBaseModel* InWidgetModel)
{
	WidgetModel = InWidgetModel;
}

void UFarmUIBaseWidget::UnBindWidgetModel()
{
	WidgetModel = nullptr;
}
