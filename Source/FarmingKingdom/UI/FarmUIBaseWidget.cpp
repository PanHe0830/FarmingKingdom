#include "FarmUIBaseWidget.h"
#include "FarmMainViewMode.h"

void UFarmUIBaseWidget::OnInit()
{
}

void UFarmUIBaseWidget::OnShow()
{
}

void UFarmUIBaseWidget::OnHide()
{
}

void UFarmUIBaseWidget::OnRecycle()
{
	if (currentViewModel.Get() != nullptr)
	{
		currentViewModel->ConditionalBeginDestroy();
		currentViewModel = nullptr;
	}
}
