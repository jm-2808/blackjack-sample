//=============================================================================================

#ifndef ENGINE_INTERACTIVEWIDGET_TEXTENTRY_H
#define ENGINE_INTERACTIVEWIDGET_TEXTENTRY_H

//=============================================================================================

#include "../InteractiveWidget.h"

//=============================================================================================

class TextInputWidget : public InteractiveWidget
{
public:
	TextInputWidget();
	TextInputWidget(std::string label, int characterLimit = 256);
	~TextInputWidget();

	//=== General ===========================================================
public:
	virtual const std::string Render() override;

	//=== Text Input =========================================================
public:
	const std::string GetValue() const { return Value; }
	void SetValue(std::string value) { Value = value; }
	void ClearValue() { Value = ""; }

	const bool IsEmpty() const { return (Value.length() == 0); }

	void SetLabel(std::string label) { Label = label; }

	void SetCharacterLimit(int limit) { CharacterLimit = limit; }

protected:
	void ToggleLock();

	void Type(Button button);

private:
	std::string Value;
	std::string Label;

	int CharacterLimit;

	//=== Input ==============================================================
public:
	void BindInputEvents(std::string toggleEvent, std::string typingEvent);
	void UnbindInputEvents();

private:
	std::string ToggleInputEvent;
	std::string TypingInputEvent;

};

//=============================================================================================

#endif

//=============================================================================================