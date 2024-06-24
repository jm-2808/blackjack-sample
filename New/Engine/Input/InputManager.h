//=============================================================================================

#ifndef ENGINE_INPUTMANAGER_H
#define ENGINE_INPUTMANAGER_H

//=============================================================================================

#include <string>
#include <map>

#include "Controller.h"
#include "InputEvent.h"

//=============================================================================================

class InputManager
{
public:
	InputManager();
	~InputManager();

	//=== Singleton =========================================================
public:
	static InputManager* Get()
	{
		if (StaticInstance == nullptr)
		{
			StaticInstance = new InputManager;
		}
		return StaticInstance;
	}

private:
	static InputManager* StaticInstance;

	//=== Controller ========================================================
public:
	void RegisterController(Controller* controller) { ControlDevice = controller; };
	Controller* GetController() { return ControlDevice; }

private:
	Controller* ControlDevice;

	//=== Events ============================================================
public:
	void RegisterKeyPress(Button button);

public:
	void AddInputEvent(std::string name, std::initializer_list<Button> buttons);
	void AddInputEvent(std::string name, std::vector<Button> buttons);

	const std::vector<Button> GetInputEventButtons(std::string inputEvent);
	const bool InputEventContainsButton(std::string inputEvent, Button button);
	const DelegateHandle BindToInputEvent(std::string inputEvent, InputEvent::FunctionType function);
	const bool UnbindFromInputEvent(std::string inputEvent, DelegateHandle handle);

private:
	std::map<std::string, InputEvent> InputEvents;

};

//=============================================================================================

#endif

//=============================================================================================