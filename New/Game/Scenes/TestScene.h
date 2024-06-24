#pragma once

// Ignore the state of this file, it is a placeholder to test the new engine update/render/input mechanics as they are developed

#include "../../Engine/Scenes.h"
#include "../../Engine/Widgets.h"

#include "../DefaultInput.h"

class TestScene : public Scene
{
public:
	TestScene()
		: Scene()
	{ 
		FrameTimePrompt = AddWidget<TextBoxWidget>();

		ButtonTestPrompt = AddWidget<TextBoxWidget>("Awaiting test...");
		ButtonTest = AddWidget<ButtonWidget>("Test button", [this](bool state) {

			std::stringstream ss;
			ss << "Test successful: #" << ++Counter;
			ButtonTestPrompt->SetText(ss.str());

			ButtonTest->UnbindInputEvent();
			ButtonTest->SetTooltip("Button Unbound");

			AnimTest->SetFrame(2);

		}, "Press to initiate test");
		ButtonTest->BindInputEvent(Game::InputEvents::Confirm);

		TextInputTest = AddWidget<TextInputWidget>("TEST:", 12);
		TextInputTest->BindInputEvents(Game::InputEvents::Confirm, Game::InputEvents::Typing);

		ImageTest = AddWidget<ImageWidget>(ASCIIImage{ " _   _ ", "( \\_/ )", "(='.'=)", "(\")_(\")" });
		AnimTest = AddWidget<AnimatedImageWidget>(std::vector<Keyframe>{
			Keyframe(0.0f, ASCIIImage{ " .o. " }), Keyframe(0.4f, ASCIIImage{ " <o> " }), Keyframe(0.8f, ASCIIImage{ " \\o/ " }),
			Keyframe(1.4f, ASCIIImage{ " <o> " }), Keyframe(1.6f, ASCIIImage{ " .o. " })
		}, true);

		// Needs to go last so pointers aren't null
		SelectorTest = AddWidget<SelectorWidget>(std::vector<InteractiveWidget*>{
			ButtonTest,
				TextInputTest
		});
		SelectorTest->BindInputEvents(Game::InputEvents::Up, Game::InputEvents::Down);
	}

	~TestScene()
	{ }

public:
	virtual void OnEnter() override 
	{ 
		SelectorTest->SetSelected(true);

		AnimTest->PlayAnimation(); 
	}
	virtual void OnExit() override {}

	virtual void Update(float deltaTime) 
	{ 
		Scene::Update(deltaTime); 

		FrameTimePrompt->SetText(std::to_string(deltaTime));
	}
	virtual void Render(std::stringstream& buffer)
	{
		buffer << "\n Frame Time: " << FrameTimePrompt->Render() << "  \n\n";
		buffer << " " << ButtonTestPrompt->Render() << "\n  " << ButtonTest->Render() << "\n\n";
		buffer << " " << TextInputTest->Render() << "\n\n";
		buffer << ImageTest->Render() << "\n\n";
		buffer << AnimTest->Render() << "\n\n";
	}

private:
	TextBoxWidget* FrameTimePrompt;

	SelectorWidget* SelectorTest;

	TextBoxWidget* ButtonTestPrompt;
	ButtonWidget* ButtonTest;

	TextInputWidget* TextInputTest;

	ImageWidget* ImageTest;
	AnimatedImageWidget* AnimTest;

	int Counter = 0;

};