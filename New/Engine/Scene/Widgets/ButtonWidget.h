//=============================================================================================

#ifndef ENGINE_INTERACTIVEWIDGET_BUTTON_H
#define ENGINE_INTERACTIVEWIDGET_BUTTON_H

//=============================================================================================

#include "../InteractiveWidget.h"

//=============================================================================================

#include "../../Types/SingleDelegate.h"

//=============================================================================================

class ButtonWidget : public InteractiveWidget
{
public:
	ButtonWidget();
	ButtonWidget(std::string text, SingleDelegate<bool>::FunctionType onClick, std::string tooltip = "");
	~ButtonWidget();

	//=== General ===========================================================
public:
	virtual const std::string Render() override;

	//=== Display ============================================================
public:
	void SetText(std::string text) { Text = text; }
	void SetTooltip(std::string tooltip) { Tooltip = tooltip; }

private:
	std::string Text;
	std::string Tooltip;

	//=== Click ==============================================================
public:
	void Click();

	void SetOnClick(SingleDelegate<bool>::FunctionType clickEvent) { OnClick.Bind(clickEvent); }

private:
	SingleDelegate<bool> OnClick;

	//=== Input ==============================================================
public:
	void BindInputEvent(std::string clickEvent);
	void UnbindInputEvent();

private:
	std::string ClickInputEvent;

};

//=============================================================================================

#endif

//=============================================================================================