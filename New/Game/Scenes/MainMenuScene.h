//=============================================================================================

#ifndef GAME_SCENE_MAINMENU_H
#define GAME_SCENE_MAINMENU_H

//=============================================================================================

#include "../../Engine/Scenes.h"
#include "../../Engine/Widgets.h"

//=============================================================================================

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	~MainMenuScene();

	//=== General ===========================================================
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;

	virtual void Update(float deltaTime) override;
	virtual void Render(std::stringstream& buffer) override;

	//=== Widgets ===========================================================
private:
	ImageWidget* TitleArt;

	SelectorWidget* MenuSelector;

	ButtonWidget* PlayButton;
	ButtonWidget* RulesButton;
	ButtonWidget* AboutButton;
	ButtonWidget* QuitButton;

};

//=============================================================================================

#endif

//=============================================================================================