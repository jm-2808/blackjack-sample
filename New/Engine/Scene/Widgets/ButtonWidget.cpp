//=============================================================================================

#include "ButtonWidget.h"

//=============================================================================================

ButtonWidget::ButtonWidget()
	: InteractiveWidget(), Text(""), Tooltip("")
{ }
ButtonWidget::ButtonWidget(std::string text, SingleDelegate<bool>::FunctionType onClick, std::string tooltip)
	: InteractiveWidget(), Text(text), Tooltip(tooltip)
{
	OnClick.Bind(onClick);
}

//=============================================================================================

ButtonWidget::~ButtonWidget()
{ }

//=============================================================================================

const std::string ButtonWidget::Render()
{
	std::stringstream ss;
	if (!IsSelected())
	{
		ss << " " << Text << " ";
	}
	else
	{
		ss << "[" << Text << "] " << Tooltip;
	}
	return ss.str();
}

//=== Click ===================================================================================

void ButtonWidget::Click()
{
	if (IsSelected())
	{
		OnClick.Broadcast(true);
	}
}

//=== Input ===================================================================================

void ButtonWidget::BindInputEvent(std::string clickEvent)
{
	if (InputComponent * input = GetInputComponent())
	{	
		UnbindInputEvent();

		input->BindToInputEvent(clickEvent, [this](std::string inputEvent, Button button) {
			Click();
		});
		ClickInputEvent = clickEvent;
	}
}

//=============================================================================================

void ButtonWidget::UnbindInputEvent()
{
	if (InputComponent * input = GetInputComponent())
	{
		if (ClickInputEvent != "")
		{
			input->UnbindFromInputEvent(ClickInputEvent);
			ClickInputEvent = "";
		}
	}
}

//=============================================================================================