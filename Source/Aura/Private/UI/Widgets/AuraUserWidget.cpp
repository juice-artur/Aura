// Aura, Copyright 2025 – 2025, Juicy, Inc.

#include "UI/Widgets/AuraUserWidget.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}