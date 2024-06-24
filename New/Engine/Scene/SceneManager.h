//=============================================================================================

#ifndef ENGINE_SCENEMANAGER_H
#define ENGINE_SCENEMANAGER_H

//=============================================================================================

#include <map>

#include "Scene.h"

//=============================================================================================

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	//=== Singleton =========================================================
public:
	static SceneManager* Get()
	{
		if (StaticInstance == nullptr)
		{
			StaticInstance = new SceneManager;
		}
		return StaticInstance;
	}

private:
	static SceneManager* StaticInstance;

	//=== Scenes ============================================================
public:
	void LoadScene(std::string name, Scene* scene);

	Scene* GetCurrentScene();
	void SetCurrentScene(std::string name);

	void UpdateCurrentScene(float deltaTime);
	void RenderCurrentScene();

private:
	std::map<std::string, Scene*> Scenes;
	std::string CurrentScene;

	std::stringstream RenderBuffer;
};

//=============================================================================================

#endif

//=============================================================================================