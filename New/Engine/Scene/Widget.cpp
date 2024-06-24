//=============================================================================================

#include "Widget.h"

//=============================================================================================

Widget::Widget()
{ }

//=============================================================================================

Widget::~Widget()
{ 
	int componentCount = Components.size();
	for (int i = 0; i < componentCount; ++i)
	{
		delete Components[i];
	}
	Components.clear();
}

//=============================================================================================

void Widget::Update(float deltaTime)
{
	int componentCount = Components.size();
	for (int i = 0; i < componentCount; ++i)
	{
		Components[i]->Update(deltaTime);
	}
}

//=============================================================================================