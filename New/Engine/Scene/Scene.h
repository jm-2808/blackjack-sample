//=============================================================================================

#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

//=============================================================================================

#include <string>
#include <sstream>
#include <vector>

#include "Widget.h"

//=============================================================================================

class Scene
{
public:
	Scene();
	~Scene();

	//=== General ===========================================================
public:
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;

	virtual void Update(float deltaTime);
	virtual void Render(std::stringstream& buffer) = 0;

	//=== Widgets ===========================================================
protected:
	template<typename WIDGET, typename... ARGUMENTS>
	WIDGET* AddWidget(ARGUMENTS... arguments)
	{
		WIDGET* widget = new WIDGET(arguments...);
		Widgets.push_back(widget);
		return widget;
	}

private:
	std::vector<Widget*> Widgets;

};

//=============================================================================================

#endif

//=============================================================================================