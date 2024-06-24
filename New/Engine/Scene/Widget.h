//=============================================================================================

#ifndef ENGINE_WIDGET_H
#define ENGINE_WIDGET_H

//=============================================================================================

#include <string>
#include <sstream>
#include <vector>

#include "WidgetComponent.h"

//=============================================================================================

class Widget
{
public:
	Widget();
	~Widget();

	//=== General ===========================================================
public:
	virtual void Update(float deltaTime);
	virtual const std::string Render() = 0;

	//=== Components ========================================================
protected:
	template<typename COMPONENT, typename... ARGUMENTS>
	COMPONENT* AddComponent(ARGUMENTS... arguments)
	{
		COMPONENT* component = new COMPONENT(arguments...);
		Components.push_back(component);
		return component;
	}

private:
	std::vector<WidgetComponent*> Components;
};

//=============================================================================================

#endif

//=============================================================================================