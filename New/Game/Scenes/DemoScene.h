//=============================================================================================

#ifndef GAME_SCENE_DEMO_H
#define GAME_SCENE_DEMO_H

//=============================================================================================

#include "../../Engine/Scenes.h"
#include "../../Engine/Widgets.h"

//=============================================================================================

class DemoScene : public Scene
{
public:
	DemoScene();
	~DemoScene();

	//=== General ===========================================================
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual void Update(float deltaTime) override;
	virtual void Render(std::stringstream& buffer) override;

	//=== Widgets ===========================================================
private:
	TextBoxWidget* InputEventPrompt;

	TextBoxWidget* SelectorPrompt;
	SelectorWidget* Selector;

	TextBoxWidget* ButtonPrompt;
	ButtonWidget* FirstButtonDemo;
	int FirstButtonCounter = 0;
	ButtonWidget* SecondButtonDemo;
	int SecondButtonCounter = 0;
	ButtonWidget* ThirdButtonDemo;
	int ThirdButtonCounter = 0;

	TextBoxWidget* TextInputPrompt;
	TextInputWidget* TextInputDemo;

	TextBoxWidget* ImagePrompt;
	ImageWidget* ImageDemo;

	TextBoxWidget* AnimationPrompt;
	AnimatedImageWidget* AnimationDemo;
	ButtonWidget* AnimationToggleButton;

};

//=============================================================================================

#endif

//=============================================================================================