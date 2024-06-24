//=============================================================================================

#include "Engine.h"

Engine* Engine::StaticInstance = nullptr;

//=============================================================================================

#include "Input/InputManager.h"
#include "Scene/SceneManager.h"

//=============================================================================================

void MainThreadFunction()
{
	float deltaTime;
	float milliseconds;

	while (!Engine::Get()->IsRequestingExit())
	{
		deltaTime = Engine::Get()->GetFrameTime();

		SceneManager::Get()->UpdateCurrentScene(deltaTime);
		SceneManager::Get()->RenderCurrentScene();

		milliseconds = deltaTime * 1000.0f;
		std::this_thread::sleep_for(std::chrono::milliseconds((int)milliseconds));
	}
}

//=============================================================================================

void InputThreadFunction()
{
	Button b;

	while (!Engine::Get()->IsRequestingExit())
	{
		b = InputManager::Get()->GetController()->GetInput();
		InputManager::Get()->RegisterKeyPress(b);
	}
}

//=============================================================================================

Engine::Engine()
{ 
	InputManager::Get();
	SceneManager::Get();

	TargetFPS = 1;
}

//=============================================================================================

Engine::~Engine()
{ 
	delete SceneManager::Get();
	delete InputManager::Get();
}

//=== Application =============================================================================

void Engine::Run()
{
	InputThread = std::async(std::launch::async, InputThreadFunction);
	MainThreadFunction();

	InputThread.get();
}

//=============================================================================================