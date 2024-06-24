//=============================================================================================

#ifndef ENGINE_INTERACTIVEWIDGET_H
#define ENGINE_INTERACTIVEWIDGET_H

//=============================================================================================

#include "Widget.h"

//=============================================================================================

#include "Components/InputComponent.h"

//=============================================================================================

class InteractiveWidget : public Widget
{
public:
	InteractiveWidget();
	~InteractiveWidget();

	//=== General ===========================================================
public:
	virtual void Update(float deltaTime) override {}
	virtual const std::string Render() override = 0;

	//=== Interactive =======================================================
protected:
	InputComponent* GetInputComponent() { return Input; }

private:
	InputComponent* Input;

	//=== Selection =====================================================
public:
	const bool IsSelected() const { return Selected; }
	void SetSelected(bool state);

	const bool IsLocked() const { return Locked; }

protected:
	void SetLocked(bool state) { Locked = state; }

private:
	virtual void OnSelected() {}
	virtual void OnDeselected() {}

private:
	bool Selected;
	bool Locked;

};

//=============================================================================================

#endif

//=============================================================================================
