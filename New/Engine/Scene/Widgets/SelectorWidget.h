//=============================================================================================

#ifndef ENGINE_INTERACTIVEWIDGET_SELECTOR_H
#define ENGINE_INTERACTIVEWIDGET_SELECTOR_H

//=============================================================================================

#include "../InteractiveWidget.h"

//=============================================================================================

#include <vector>

//=============================================================================================

class SelectorWidget : public InteractiveWidget
{
public:
	SelectorWidget();
	SelectorWidget(std::vector<InteractiveWidget*> widgets);
	~SelectorWidget();

	//=== General ===========================================================
public:
	virtual const std::string Render() override { return ""; }

	//=== Selection =====================================================
private:
	virtual void OnSelected() override;
	virtual void OnDeselected() override;

	//=== Widget Selection ==================================================
public:
	void SetWidgets(std::initializer_list<InteractiveWidget*> widgets) { Widgets = widgets; }

	InteractiveWidget* GetCurrentWidget();

	void SetCurrentWidget(int index);
	void SetCurrentWidget(InteractiveWidget* widget);

private:
	void ShiftCurrentWidget(int step);

private:
	std::vector<InteractiveWidget*> Widgets;
	int CurrentWidget;

	//=== Input ==============================================================
public:
	void BindInputEvents(std::string shiftUpEvent, std::string shiftDownEvent);
	void UnbindInputEvents();

private:
	std::string ShiftUpInputEvent;
	std::string ShiftDownInputEvent;

};

//=============================================================================================

#endif

//=============================================================================================