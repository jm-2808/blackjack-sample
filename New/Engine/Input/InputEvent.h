//=============================================================================================

#ifndef ENGINE_INPUTEVENT_H
#define ENGINE_INPUTEVENT_H

//=============================================================================================

#include <string>
#include <vector>

#include "Buttons.h"
#include "../Types/MultiDelegate.h"

//=============================================================================================

class InputEvent
{
public:
	InputEvent() {}

	InputEvent(std::vector<Button> buttons)
		: Buttons(buttons)
	{ }


	//=== Types =============================================================
public:
	typedef MultiDelegate<std::string, Button>::FunctionType FunctionType;

	//=== Buttons ===========================================================
public:
	const std::vector<Button> GetButtons() const { return Buttons; }
	const int GetButtonCount() const { return Buttons.size(); }

	const bool ContainsButton(Button button)
	{
		bool containsButton = false;
		int buttonCount = Buttons.size();
		for (int i = 0; i < buttonCount; ++i)
		{
			if (Buttons[i] == button)
			{
				containsButton = true;
			}
		}
		return containsButton;
	}

private:
	std::vector<Button> Buttons;

	//=== Delegate ==========================================================
public:
	void Trigger(std::string inputEvent, Button button) const { OnTriggered.Broadcast(inputEvent, button); }

	const DelegateHandle Bind(InputEvent::FunctionType function) { return OnTriggered.Bind(function); }
	const bool Unbind(DelegateHandle handle) { return OnTriggered.Unbind(handle); }

private:
	MultiDelegate<std::string, Button> OnTriggered;

};

//=============================================================================================

#endif

//=============================================================================================