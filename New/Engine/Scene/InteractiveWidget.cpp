//=============================================================================================

#include "InteractiveWidget.h"

//=============================================================================================

InteractiveWidget::InteractiveWidget()
	: Widget(), Selected(false), Locked(false)
{ 
	Input = AddComponent<InputComponent>();
}

//=============================================================================================

InteractiveWidget::~InteractiveWidget()
{ }

//=== Selection ===============================================================================

void InteractiveWidget::SetSelected(bool state)
{ 
	Selected = state;
	if (state)
	{
		OnSelected();
	}
	else
	{
		OnDeselected();
	}
}

//=============================================================================================