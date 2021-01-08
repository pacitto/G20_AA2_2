#pragma once
#include "Scene.h"
#include "MenuScene.h"
#include "Map1Scene.h"
#include "Map2Scene.h"
#include "RankingScene.h"
#include "Inputs.h"
#include "Constants.h"

class Game
{
private:
	Inputs input;
	Scene *currentScene;
public:
	bool running;
	GameStates state;
	Game();
	void LoadMenu();
	void LoadMap1();
	void LoadMap2();
	void LoadRanking();
	void RunGame();
	void Draw();
	~Game();
};

