//=============================================================================================

#ifndef ENGINE_WIDGETCOMPONENT_INPUT_H
#define ENGINE_WIDGETCOMPONENT_INPUT_H

//=============================================================================================

#include "../WidgetComponent.h"

//=============================================================================================

#include <map>

#include "../../Input/InputEvent.h"
#include "../../Types/DelegateHandle.h"

//=============================================================================================

class InputComponent : public WidgetComponent
{
public:
	InputComponent();
	~InputComponent();

	//=== General ===========================================================
public:
	virtual void Update(float deltaTime) override {};

	//=== Input ============================================================
public:
	void BindToInputEvent(std::string inputEvent, InputEvent::FunctionType function);
	const bool UnbindFromInputEvent(std::string inputEvent);
	void UnbindFromAllInputEvents();

	const int GetHandleCount() const { return Handles.size(); }

private:
	std::map<std::string, DelegateHandle> Handles;
};

//=============================================================================================

#endif

//=============================================================================================