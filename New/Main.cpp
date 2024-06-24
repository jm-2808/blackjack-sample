//=============================================================================================

#include "Engine/Engine.h"

#include "Engine/Managers.h"
#include "Engine/InputMethods.h"

//=============================================================================================

#include "Game/DefaultInput.h"
#include "Game/DefaultScenes.h"

//=============================================================================================

int main()
{
	//==========================================================================

	// Initialise engine
	Engine::Get()->SetTargetFPS(30); // 1 = Stable, bad deltaTime | 30 = Slightly flickery, decent deltaTime | 60 = Quite flickery, very good deltaTime

	//==========================================================================
	// Input

	Keyboard kb;

	if (InputManager* inputManager = InputManager::Get())
	{
		inputManager->RegisterController(&kb);

		inputManager->AddInputEvent(Game::InputEvents::Typing, {
				Button::KEYBOARD_A, Button::KEYBOARD_B, Button::KEYBOARD_C, Button::KEYBOARD_D, Button::KEYBOARD_E, Button::KEYBOARD_F,
				Button::KEYBOARD_G, Button::KEYBOARD_H, Button::KEYBOARD_I, Button::KEYBOARD_J, Button::KEYBOARD_K, Button::KEYBOARD_L,
				Button::KEYBOARD_M, Button::KEYBOARD_N, Button::KEYBOARD_O, Button::KEYBOARD_P, Button::KEYBOARD_Q, Button::KEYBOARD_R,
				Button::KEYBOARD_S, Button::KEYBOARD_T, Button::KEYBOARD_U, Button::KEYBOARD_V, Button::KEYBOARD_W, Button::KEYBOARD_X,
				Button::KEYBOARD_Y, Button::KEYBOARD_Z,
				Button::KEYBOARD_0, Button::KEYBOARD_1, Button::KEYBOARD_2, Button::KEYBOARD_3, Button::KEYBOARD_4,
				Button::KEYBOARD_5, Button::KEYBOARD_6, Button::KEYBOARD_7, Button::KEYBOARD_8, Button::KEYBOARD_9,
				Button::KEYBOARD_SPACE, Button::KEYBOARD_BACKSPACE
			});

		inputManager->AddInputEvent(Game::InputEvents::Up,		{ Button::KEYBOARD_W, Button::KEYBOARD_ARROWUP });
		inputManager->AddInputEvent(Game::InputEvents::Down,	{ Button::KEYBOARD_S, Button::KEYBOARD_ARROWDOWN });
		inputManager->AddInputEvent(Game::InputEvents::Confirm, { Button::KEYBOARD_ENTER });
		inputManager->AddInputEvent(Game::InputEvents::Exit,	{ Button::KEYBOARD_ESCAPE });
	}

	//==========================================================================
	//Scenes

	if (SceneManager* sceneManager = SceneManager::Get())
	{
		sceneManager->LoadScene(Game::Scenes::MainMenu, new MainMenuScene());
		sceneManager->LoadScene(Game::Scenes::Demo, new DemoScene());

		sceneManager->SetCurrentScene(Game::Scenes::MainMenu);
	}

	//==========================================================================

	Engine::Get()->Run();

	//==========================================================================

	// Remove engine
	delete Engine::Get();

	//==========================================================================

	return 0;
}

//=============================================================================================