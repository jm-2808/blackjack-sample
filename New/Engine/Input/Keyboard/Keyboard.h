//=============================================================================================

#ifndef ENGINE_CONTROLLER_KEYBOARD_H
#define ENGINE_CONTROLLER_KEYBOARD_H

//=============================================================================================

#include "../Controller.h"

//=============================================================================================

class Keyboard : public Controller
{
public:
	Keyboard();
	~Keyboard();

	//=== General ===========================================================
public:
	virtual void OnRegistered() {};
	virtual void OnUnregistered() {};

	//=== Input =============================================================
public:
	virtual const Button GetInput() const override;
	virtual const int GetRawInput() const override;


};

//=============================================================================================

#endif

//=============================================================================================