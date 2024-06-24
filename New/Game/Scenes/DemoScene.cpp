//=============================================================================================

#include "DemoScene.h"

//=============================================================================================

#include "../../Engine/Engine.h"
#include "../../Engine/Managers.h"

#include "../DefaultScenes.h"
#include "../DefaultInput.h"

//=============================================================================================

DemoScene::DemoScene()
	: Scene()
{
	SelectorPrompt = AddWidget<TextBoxWidget>("A Selector Widget allows users to navigate between widgets, and will\n shift the selection up/down when the bound input events are triggered");

	ButtonPrompt = AddWidget<TextBoxWidget>("While selected, Button Widgets will trigger a function when their bound\n input event is triggered");

	FirstButtonDemo = AddWidget<ButtonWidget>("Button 1", [this](bool state) {
		std::stringstream ss;
		ss << "I have been pressed #" << ++FirstButtonCounter << " times";
		FirstButtonDemo->SetTooltip(ss.str());
	}, "I haven't been pressed yet");
	FirstButtonDemo->BindInputEvent(Game::InputEvents::Confirm);

	SecondButtonDemo = AddWidget<ButtonWidget>("Button 2", [this](bool state) {
		std::stringstream ss;
		ss << "I have been pressed #" << ++SecondButtonCounter << " times";
		SecondButtonDemo->SetTooltip(ss.str());
	}, "I haven't been pressed yet");
	SecondButtonDemo->BindInputEvent(Game::InputEvents::Confirm);

	ThirdButtonDemo = AddWidget<ButtonWidget>("Button 3", [this](bool state) {
		std::stringstream ss;
		ss << "I have been pressed #" << ++ThirdButtonCounter << " times";
		ThirdButtonDemo->SetTooltip(ss.str());
	}, "I haven't been pressed yet");
	ThirdButtonDemo->BindInputEvent(Game::InputEvents::Confirm);

	TextInputPrompt = AddWidget<TextBoxWidget>("Text Input Widgets need to be locked before users can enter text\n When the bound input event is triggered, the lock toggles and users can enter text");

	TextInputDemo = AddWidget<TextInputWidget>("Enter Text:", 32);
	TextInputDemo->BindInputEvents(Game::InputEvents::Confirm, Game::InputEvents::Typing);

	ImagePrompt = AddWidget<TextBoxWidget>("Image Widgets provide a simple method to display an ASCII art 'image'");
	ImageDemo = AddWidget<ImageWidget>(ASCIIImage{ " _   _ ", "( \\_/ )", "(='.'=)", "(\")_(\")" });;

	AnimationPrompt = AddWidget<TextBoxWidget>("Animated Image Widgets allow users to define a series of ASCII art 'images',\n with time stamps, which can be cycled");
	AnimationDemo = AddWidget<AnimatedImageWidget>(std::vector<Keyframe>{
		Keyframe(0.0f, ASCIIImage{ " .o. " }), Keyframe(0.4f, ASCIIImage{ " <o> " }), Keyframe(0.8f, ASCIIImage{ " \\o/ " }),
		Keyframe(1.4f, ASCIIImage{ " <o> " }), Keyframe(1.6f, ASCIIImage{ " .o. " })
	}, true);
	AnimationToggleButton = AddWidget<ButtonWidget>("Play Animation", [this](bool state) {
		if (AnimationDemo->IsPlaying())
		{
			AnimationDemo->StopAnimation();
			AnimationToggleButton->SetText("Play Animation");
		}
		else
		{
			AnimationDemo->PlayAnimation();
			AnimationToggleButton->SetText("Stop Animation");
		}
	}, "Toggle the animation");
	AnimationToggleButton->BindInputEvent(Game::InputEvents::Confirm);

	Selector = AddWidget<SelectorWidget>(std::vector<InteractiveWidget*>{
		FirstButtonDemo,
		SecondButtonDemo,
		ThirdButtonDemo,
		TextInputDemo,
		AnimationToggleButton
	});
	Selector->BindInputEvents(Game::InputEvents::Up, Game::InputEvents::Down);
}

//=============================================================================================

DemoScene::~DemoScene()
{ }

//=============================================================================================

void DemoScene::OnEnter()
{
	Selector->SetSelected(true);
}

//=============================================================================================

void DemoScene::OnExit()
{
	Selector->SetSelected(false);
}

//=============================================================================================

void DemoScene::Update(float deltaTime)
{ 
	Scene::Update(deltaTime);
}

//=============================================================================================

void DemoScene::Render(std::stringstream& buffer)
{
	buffer << "\n " << SelectorPrompt->Render();

	buffer << "\n\n " << ButtonPrompt->Render();
	buffer << "\n " << FirstButtonDemo->Render();
	buffer << "\n " << SecondButtonDemo->Render();
	buffer << "\n " << ThirdButtonDemo->Render();

	buffer << "\n\n " << TextInputPrompt->Render();
	buffer << "\n " << TextInputDemo->Render();

	buffer << "\n\n " << ImagePrompt->Render();
	buffer << "\n " << ImageDemo->Render();

	buffer << "\n\n " << AnimationPrompt->Render();
	buffer << "\n " << AnimationDemo->Render();
	buffer << "\n " << AnimationToggleButton->Render();


	buffer << "\n\n";
}

//=============================================================================================