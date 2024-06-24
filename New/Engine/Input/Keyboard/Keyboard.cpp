//=============================================================================================

#include "Keyboard.h"

//=============================================================================================

#include <Windows.h>
#include <conio.h>

//=============================================================================================

Keyboard::Keyboard()
	: Controller()
{ }

//=============================================================================================

Keyboard::~Keyboard()
{ }

//=============================================================================================

const Button Keyboard::GetInput() const
{
	int key = GetRawInput();
	switch (key)
	{
	case 0:
	case 224:
	{
		// Special keys
		key = GetRawInput();
		switch (key)
		{
		case 72:
			return Button::KEYBOARD_ARROWUP;
		case 80:
			return Button::KEYBOARD_ARROWDOWN;
		case 75:
			return Button::KEYBOARD_ARROWLEFT;
		case 77:
			return Button::KEYBOARD_ARROWRIGHT;
		default:
			return Button::UNKNOWN;
		}
	}
	case 8:
		return Button::KEYBOARD_BACKSPACE;
	case 9:
		return Button::KEYBOARD_TAB;
	case 13:
		return Button::KEYBOARD_ENTER;
	case 27:
		return Button::KEYBOARD_ESCAPE;
	case 32:
		return Button::KEYBOARD_SPACE;
	case 48:
		return Button::KEYBOARD_0;
	case 49:
		return Button::KEYBOARD_1;
	case 50:
		return Button::KEYBOARD_2;
	case 51:
		return Button::KEYBOARD_3;
	case 52:
		return Button::KEYBOARD_4;
	case 53:
		return Button::KEYBOARD_5;
	case 54:
		return Button::KEYBOARD_6;
	case 55:
		return Button::KEYBOARD_7;
	case 56:
		return Button::KEYBOARD_8;
	case 57:
		return Button::KEYBOARD_9;
	case 97:
		return Button::KEYBOARD_A;
	case 98:
		return Button::KEYBOARD_B;
	case 99:
		return Button::KEYBOARD_C;
	case 100:
		return Button::KEYBOARD_D;
	case 101:
		return Button::KEYBOARD_E;
	case 102:
		return Button::KEYBOARD_F;
	case 103:
		return Button::KEYBOARD_G;
	case 104:
		return Button::KEYBOARD_H;
	case 105:
		return Button::KEYBOARD_I;
	case 106:
		return Button::KEYBOARD_J;
	case 107:
		return Button::KEYBOARD_K;
	case 108:
		return Button::KEYBOARD_L;
	case 109:
		return Button::KEYBOARD_M;
	case 110:
		return Button::KEYBOARD_N;
	case 111:
		return Button::KEYBOARD_O;
	case 112:
		return Button::KEYBOARD_P;
	case 113:
		return Button::KEYBOARD_Q;
	case 114:
		return Button::KEYBOARD_R;
	case 115:
		return Button::KEYBOARD_S;
	case 116:
		return Button::KEYBOARD_T;
	case 117:
		return Button::KEYBOARD_U;
	case 118:
		return Button::KEYBOARD_V;
	case 119:
		return Button::KEYBOARD_W;
	case 120:
		return Button::KEYBOARD_X;
	case 121:
		return Button::KEYBOARD_Y;
	case 122:
		return Button::KEYBOARD_Z;
	default:
		return Button::UNKNOWN;
	}
}

//=============================================================================================

const int Keyboard::GetRawInput() const
{
	return _getch();
}

//=============================================================================================