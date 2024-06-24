//=============================================================================================

#include "InputManager.h"

InputManager* InputManager::StaticInstance = nullptr;

//=============================================================================================

InputManager::InputManager()
	: ControlDevice(nullptr)
{ }

//=============================================================================================

InputManager::~InputManager()
{ }


//=== Events ==================================================================================

void InputManager::RegisterKeyPress(Button button)
{
	for (const std::pair<std::string, InputEvent>& event : InputEvents)
	{
		if (InputEventContainsButton(event.first, button))
		{
			event.second.Trigger(event.first, button);
		}
	}
}

//=============================================================================================

void InputManager::AddInputEvent(std::string name, std::initializer_list<Button> buttons)
{
	InputEvents[name] = InputEvent(buttons);
}
void InputManager::AddInputEvent(std::string name, std::vector<Button> buttons)
{
	InputEvents[name] = InputEvent(buttons);
}

//=============================================================================================

const std::vector<Button> InputManager::GetInputEventButtons(std::string inputEvent)
{
	if (InputEvents.find(inputEvent) != InputEvents.end())
	{
		return InputEvents[inputEvent].GetButtons();
	}
	return std::vector<Button>();
}

//=============================================================================================

const bool InputManager::InputEventContainsButton(std::string inputEvent, Button button)
{
	if (InputEvents.find(inputEvent) != InputEvents.end())
	{
		return InputEvents[inputEvent].ContainsButton(button);
	}
	return false;
}

//=============================================================================================

const DelegateHandle InputManager::BindToInputEvent(std::string inputEvent, InputEvent::FunctionType function)
{
	if (InputEvents.find(inputEvent) != InputEvents.end())
	{
		return InputEvents[inputEvent].Bind(function);
	}
	return DelegateHandle();
}

//=============================================================================================

const bool InputManager::UnbindFromInputEvent(std::string inputEvent, DelegateHandle handle)
{
	if (InputEvents.find(inputEvent) != InputEvents.end())
	{
		return InputEvents[inputEvent].Unbind(handle);
	}
	return false;
}

//=============================================================================================