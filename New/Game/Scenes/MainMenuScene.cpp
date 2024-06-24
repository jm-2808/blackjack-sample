//=============================================================================================

#include "MainMenuScene.h"

//=============================================================================================

#include "../../Engine/Engine.h"
#include "../../Engine/Managers.h"

#include "../DefaultScenes.h"
#include "../DefaultInput.h"

//=============================================================================================

MainMenuScene::MainMenuScene()
	: Scene()
{ 
	TitleArt = AddWidget<ImageWidget>(ASCIIImage{ 
		"                         __ ",
		"                   _..-''--'----_. ",
		"                 ,''.-''| .---/ _`-._ ",
		"               ,' \\ \\  ;| | ,/ / `-._`-. ",
		"             ,' ,',\\ \\( | |// /,-._  / / ",
		"             ;.`. `,\\ \\`| |/ / |   )/ / ",
		"            / /`_`.\\_\\ \\| /_.-.'-''/ / ",
		"           / /_|_:.`. \\ |;'`..')  / / ",
		"           `-._`-._`.`.;`.\\  ,'  / / ",
		"               `-._`.`/    ,'-._/ / ",
		"                 : `-/     \\`-.._/ ",
		"                 |  :      ;._ ( ",
		"                 :  |      \\  ` \\ ",
		"                  \\         \\   | ",
		"     ____  _            _     _            _     ",
		"    | __ )| | __ _  ___| | __(_) __ _  ___| | __ ",
		"    |  _ \\| |/ _` |/ __| |/ /| |/ _` |/ __| |/ / ",
		"    | |_) | | (_| | (__|   < | | (_| | (__|   <  ",
		"    |____/|_|\\__,_|\\___|_|\\_\\/ |\\__,_|\\___|_|\\_\\ ",
		"                           |__/                   21"
	});

	PlayButton = AddWidget<ButtonWidget>("Play", [this](bool state) { 
		SceneManager::Get()->SetCurrentScene(Game::Scenes::Demo);
	}, "Begin the game (Currently loads demo scene)");
	PlayButton->BindInputEvent(Game::InputEvents::Confirm);

	RulesButton = AddWidget<ButtonWidget>("Rules", [this](bool state) {}, "Learn the rules of Blackjack");
	RulesButton->BindInputEvent(Game::InputEvents::Confirm);

	AboutButton = AddWidget<ButtonWidget>("About", [this](bool state) {}, "Find out who developed this project");
	AboutButton->BindInputEvent(Game::InputEvents::Confirm);

	QuitButton = AddWidget<ButtonWidget>("Quit", [this](bool state) {
		Engine::Get()->RequestExit();
	}, "It's a quit button, you tell me what it does");
	QuitButton->BindInputEvent(Game::InputEvents::Confirm);

	MenuSelector = AddWidget<SelectorWidget>(std::vector<InteractiveWidget*>{
		PlayButton,
		RulesButton,
		AboutButton,
		QuitButton
	});
	MenuSelector->BindInputEvents(Game::InputEvents::Up, Game::InputEvents::Down);
}

//=============================================================================================

MainMenuScene::~MainMenuScene()
{ }

//=============================================================================================

void MainMenuScene::OnEnter()
{
	MenuSelector->SetSelected(true);
}

//=============================================================================================

void MainMenuScene::OnExit()
{
	MenuSelector->SetSelected(false);
}

//=============================================================================================

void MainMenuScene::Update(float deltaTime)
{ 
	Scene::Update(deltaTime);
}

//=============================================================================================

void MainMenuScene::Render(std::stringstream& buffer)
{
	buffer << "\n" << TitleArt->Render() << "\n";
	buffer << "\n                    " << PlayButton->Render();
	buffer << "\n                    " << RulesButton->Render();
	buffer << "\n                    " << AboutButton->Render();
	buffer << "\n                    " << QuitButton->Render();
	buffer << "\n\n";
}

//=============================================================================================