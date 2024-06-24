//=============================================================================================

#include "SelectorWidget.h"

//=============================================================================================

SelectorWidget::SelectorWidget()
	: InteractiveWidget(), CurrentWidget(0)
{ }

SelectorWidget::SelectorWidget(std::vector<InteractiveWidget*> widgets)
	: InteractiveWidget(), CurrentWidget(0), Widgets(widgets)
{ }

//=============================================================================================

SelectorWidget::~SelectorWidget()
{ }

//=== Selection ===============================================================================

void SelectorWidget::OnSelected()
{
	if (GetCurrentWidget() != nullptr)
	{
		GetCurrentWidget()->SetSelected(true);
	}
}

//=============================================================================================

void SelectorWidget::OnDeselected()
{
	if (GetCurrentWidget() != nullptr)
	{
		GetCurrentWidget()->SetSelected(false);
	}
}

//=== Widget Selection ========================================================================

InteractiveWidget* SelectorWidget::GetCurrentWidget()
{
	if (Widgets.size() > 0)
	{
		return Widgets[CurrentWidget];
	}
	return nullptr;
}

//=============================================================================================

void SelectorWidget::SetCurrentWidget(int index)
{
	ShiftCurrentWidget(index);
}
void SelectorWidget::SetCurrentWidget(InteractiveWidget* widget)
{

}

//=============================================================================================

void SelectorWidget::ShiftCurrentWidget(int index)
{
	if (IsSelected())
	{
		if (!GetCurrentWidget()->IsLocked())
		{
			if (index >= 0 && index < Widgets.size())
			{
				if (GetCurrentWidget() != nullptr)
				{
					GetCurrentWidget()->SetSelected(false);
				}
				CurrentWidget = index;
				if (GetCurrentWidget() != nullptr)
				{
					GetCurrentWidget()->SetSelected(true);
				}
			}
		}
	}
}

//=== Input ===================================================================================

void SelectorWidget::BindInputEvents(std::string shiftUpEvent, std::string shiftDownEvent)
{
	if (InputComponent * input = GetInputComponent())
	{
		UnbindInputEvents();

		input->BindToInputEvent(shiftUpEvent, [this](std::string inputEvent, Button button) {
			ShiftCurrentWidget(CurrentWidget - 1);
		});
		ShiftUpInputEvent = shiftUpEvent;

		input->BindToInputEvent(shiftDownEvent, [this](std::string inputEvent, Button button) {
			ShiftCurrentWidget(CurrentWidget + 1);
		});
		ShiftDownInputEvent = shiftDownEvent;
	}
}

//=============================================================================================

void SelectorWidget::UnbindInputEvents()
{
	if (InputComponent * input = GetInputComponent())
	{
		if (ShiftUpInputEvent != "")
		{
			input->UnbindFromInputEvent(ShiftUpInputEvent);
			ShiftUpInputEvent = "";
		}

		if (ShiftDownInputEvent != "")
		{
			input->UnbindFromInputEvent(ShiftDownInputEvent);
			ShiftDownInputEvent = "";
		}
	}
}

//=============================================================================================