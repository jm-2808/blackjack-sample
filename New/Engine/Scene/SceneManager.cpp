//=============================================================================================

#include "SceneManager.h"

SceneManager* SceneManager::StaticInstance = nullptr;

//=============================================================================================

#include <iostream>

//=============================================================================================

SceneManager::SceneManager()
{ }

//=============================================================================================

SceneManager::~SceneManager()
{ 
	for (const std::pair<std::string, Scene*>& scene : Scenes)
	{
		if (scene.second != nullptr)
		{
			delete scene.second;
		}
	}
	Scenes.clear();
}

//=== Scenes ==================================================================================

void SceneManager::LoadScene(std::string name, Scene* scene)
{
	Scenes[name] = scene;
}

//=============================================================================================

Scene* SceneManager::GetCurrentScene()
{
	if (Scenes.find(CurrentScene) != Scenes.end())
	{
		return Scenes[CurrentScene];
	}
	return nullptr;
}

//=============================================================================================

void SceneManager::SetCurrentScene(std::string name)
{
	if (Scenes.find(name) != Scenes.end())
	{
		// Exit previous scene
		if (GetCurrentScene() != nullptr)
		{
			GetCurrentScene()->OnExit();
		}

		// Enter new scene
		CurrentScene = name;

		if (GetCurrentScene() != nullptr)
		{
			GetCurrentScene()->OnEnter();
		}
	}
}

//=============================================================================================

void SceneManager::UpdateCurrentScene(float deltaTime)
{
	GetCurrentScene()->Update(deltaTime);
}

//=============================================================================================

void SceneManager::RenderCurrentScene()
{
	// Probably inefficient, but this is a windows console so we already have low standards
	std::stringstream oldBuffer(RenderBuffer.str());	// Copy current frame
	RenderBuffer = std::stringstream();					// Clear buffer
	GetCurrentScene()->Render(RenderBuffer);			// Render new frame to buffer

	if (RenderBuffer.str() != oldBuffer.str())			// If it has actually changed (helps prevent constant flickering)
	{
		system("cls");									// Clear previous frame -> this isn't great, should fix later ("system(..)" is slow and OS specific)
		std::cout << RenderBuffer.str();				// Output new frame
	}
}

//=============================================================================================