//=============================================================================================

#include "TextInputWidget.h"

//=============================================================================================

TextInputWidget::TextInputWidget()
	: InteractiveWidget(), Value(""), Label(""), CharacterLimit(256)
{ }
TextInputWidget::TextInputWidget(std::string label, int characterLimit)
	: InteractiveWidget(), Value(""), Label(label), CharacterLimit(characterLimit)
{ }

//=============================================================================================

TextInputWidget::~TextInputWidget()
{ }

//=============================================================================================

const std::string TextInputWidget::Render()
{
	std::stringstream ss;
	if (!IsSelected())
	{
		ss << Label << "   " << Value << "  ";
	}
	else
	{
		if (IsLocked())
		{
			ss << Label << " { " << Value << "_}";
		}
		else
		{
			ss << Label << " [ " << Value << " ]";
		}
	}
	return ss.str();
}

//=== Text Input ==============================================================================

void TextInputWidget::ToggleLock()
{
	if (IsSelected())
	{
		SetLocked(!IsLocked());
	}
}

//=============================================================================================

void TextInputWidget::Type(Button button)
{
	if (IsSelected() && IsLocked())
	{
		if (button == KEYBOARD_BACKSPACE)
		{
			if (Value.length() > 0)
			{
				Value = Value.substr(0, Value.length() - 1);
			}
		}
		else if (button == Button::KEYBOARD_SPACE)
		{
			if (Value.size() < CharacterLimit)
			{
				std::stringstream ss;
				ss << Value << " ";
				Value = ss.str();
			}
		}
		else
		{
			if (Value.size() < CharacterLimit)
			{
				std::stringstream ss;
				ss << Value << button;
				Value = ss.str();
			}
		}
	}
}

//=== Input ===================================================================================

void TextInputWidget::BindInputEvents(std::string toggleEvent, std::string typingEvent)
{
	if (InputComponent * input = GetInputComponent())
	{
		UnbindInputEvents();

		input->BindToInputEvent(toggleEvent, [this](std::string inputEvent, Button button) {
			ToggleLock();
		});
		ToggleInputEvent = toggleEvent;

		input->BindToInputEvent(typingEvent, [this](std::string inputEvent, Button button) {
			Type(button);
		});
		TypingInputEvent = typingEvent;
	}
}

//=============================================================================================

void TextInputWidget::UnbindInputEvents()
{
	if (InputComponent * input = GetInputComponent())
	{
		if (ToggleInputEvent != "")
		{
			input->UnbindFromInputEvent(ToggleInputEvent);
			ToggleInputEvent = "";
		}

		if (TypingInputEvent != "")
		{
			input->UnbindFromInputEvent(TypingInputEvent);
			TypingInputEvent = "";
		}
	}
}

//=============================================================================================