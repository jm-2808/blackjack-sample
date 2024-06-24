//=============================================================================================

#ifndef ENGINE_CONTROLLER_BUTTONS_H
#define ENGINE_CONTROLLER_BUTTONS_H

//=============================================================================================

#include <ostream>

//=============================================================================================

enum Button
{
	// Keyboard
	KEYBOARD_A, KEYBOARD_B, KEYBOARD_C, KEYBOARD_D, KEYBOARD_E, KEYBOARD_F, 
	KEYBOARD_G, KEYBOARD_H, KEYBOARD_I, KEYBOARD_J, KEYBOARD_K, KEYBOARD_L, 
	KEYBOARD_M, KEYBOARD_N, KEYBOARD_O, KEYBOARD_P, KEYBOARD_Q, KEYBOARD_R, 
	KEYBOARD_S, KEYBOARD_T, KEYBOARD_U, KEYBOARD_V, KEYBOARD_W, KEYBOARD_X, 
	KEYBOARD_Y, KEYBOARD_Z,
	KEYBOARD_0, KEYBOARD_1, KEYBOARD_2, KEYBOARD_3, KEYBOARD_4, 
	KEYBOARD_5, KEYBOARD_6, KEYBOARD_7, KEYBOARD_8, KEYBOARD_9,
	KEYBOARD_TAB, KEYBOARD_SPACE, KEYBOARD_BACKSPACE, 
	KEYBOARD_ENTER, KEYBOARD_ESCAPE,
	KEYBOARD_ARROWUP, KEYBOARD_ARROWDOWN, KEYBOARD_ARROWLEFT, KEYBOARD_ARROWRIGHT,

	NONE, UNKNOWN
};

//=============================================================================================

std::ostream& operator<<(std::ostream& os, Button& button);

//=============================================================================================

#endif

//=============================================================================================