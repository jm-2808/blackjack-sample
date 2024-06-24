//=============================================================================================

#include "InputComponent.h"

//=============================================================================================

#include "../../Input/InputManager.h"

//=============================================================================================

InputComponent::InputComponent()
	: WidgetComponent()
{ }

//=============================================================================================

InputComponent::~InputComponent()
{ 
	Handles.clear();
}

//=== Interactive =============================================================================

void InputComponent::BindToInputEvent(std::string inputEvent, InputEvent::FunctionType function)
{
	if (InputManager * input = InputManager::Get())
	{
		DelegateHandle handle = input->BindToInputEvent(inputEvent, function);
		if (handle.IsValid())
		{
			Handles[inputEvent] = handle;
		}
	}
}

//=============================================================================================

const bool InputComponent::UnbindFromInputEvent(std::string inputEvent)
{
	if (InputManager * input = InputManager::Get())
	{
		std::map<std::string, DelegateHandle>::iterator it = Handles.find(inputEvent);
		if (it != Handles.end())
		{
			if (input->UnbindFromInputEvent(inputEvent, Handles[inputEvent]))
			{
				Handles.erase(it);
				return true;
			}
		}
	}
	return false;
}

//=============================================================================================

void InputComponent::UnbindFromAllInputEvents()
{
	if (InputManager * input = InputManager::Get())
	{
		for (const std::pair<std::string, DelegateHandle>& handle : Handles)
		{
			input->UnbindFromInputEvent(handle.first, handle.second);
		}
		Handles.clear();
	}
}

//=============================================================================================