//=============================================================================================

#include "Buttons.h"

//=============================================================================================

std::ostream& operator<<(std::ostream& os, Button& button)
{
	switch (button)
	{
	case KEYBOARD_A: { os << 'A'; break; }
	case KEYBOARD_B: { os << 'B'; break; }
	case KEYBOARD_C: { os << 'C'; break; }
	case KEYBOARD_D: { os << 'D'; break; }
	case KEYBOARD_E: { os << 'E'; break; }
	case KEYBOARD_F: { os << 'F'; break; }
	case KEYBOARD_G: { os << 'G'; break; }
	case KEYBOARD_H: { os << 'H'; break; }
	case KEYBOARD_I: { os << 'I'; break; }
	case KEYBOARD_J: { os << 'J'; break; }
	case KEYBOARD_K: { os << 'K'; break; }
	case KEYBOARD_L: { os << 'L'; break; }
	case KEYBOARD_M: { os << 'M'; break; }
	case KEYBOARD_N: { os << 'N'; break; }
	case KEYBOARD_O: { os << 'O'; break; }
	case KEYBOARD_P: { os << 'P'; break; }
	case KEYBOARD_Q: { os << 'Q'; break; }
	case KEYBOARD_R: { os << 'R'; break; }
	case KEYBOARD_S: { os << 'S'; break; }
	case KEYBOARD_T: { os << 'T'; break; }
	case KEYBOARD_U: { os << 'U'; break; }
	case KEYBOARD_V: { os << 'V'; break; }
	case KEYBOARD_W: { os << 'W'; break; }
	case KEYBOARD_X: { os << 'X'; break; }
	case KEYBOARD_Y: { os << 'Y'; break; }
	case KEYBOARD_Z: { os << 'Z'; break; }

	case KEYBOARD_0: { os << 'Z'; break; }
	case KEYBOARD_1: { os << 'Z'; break; }
	case KEYBOARD_2: { os << 'Z'; break; }
	case KEYBOARD_3: { os << 'Z'; break; }
	case KEYBOARD_4: { os << 'Z'; break; }
	case KEYBOARD_5: { os << 'Z'; break; }
	case KEYBOARD_6: { os << 'Z'; break; }
	case KEYBOARD_7: { os << 'Z'; break; }
	case KEYBOARD_8: { os << 'Z'; break; }
	case KEYBOARD_9: { os << 'Z'; break; }

	default: { os << '?'; break; }
	}

	return os;
}

//=============================================================================================