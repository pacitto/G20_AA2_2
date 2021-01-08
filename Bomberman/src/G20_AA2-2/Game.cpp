#include "Game.h"

Game::Game()
{
	running = true;
	state = GameStates::MENU;
	currentScene = new MenuScene();
}

void Game::LoadMenu()
{
	state = GameStates::MENU;
	delete currentScene;
	currentScene = new MenuScene();
}

void Game::LoadMap1()
{
	state = GameStates::MAP_1;
	delete currentScene;
	currentScene = new Map1Scene();
}

void Game::LoadMap2()
{
	state = GameStates::MAP_2;
	delete currentScene;
	currentScene = new Map2Scene();
}

void Game::LoadRanking()
{
	state = GameStates::RANKING;
	delete currentScene;
	currentScene = new RankingScene();
}

void Game::RunGame()
{
	input.UpdateInputs();

	if (input.GetKey(InputKey::QUIT)) state = GameStates::EXIT;

	switch (state)
	{
	case GameStates::MENU:
		if (currentScene->state == SceneStates::CLICK_MAP1)
		{
			LoadMap1();
		}
		if (currentScene->state == SceneStates::CLICK_MAP2)
		{
			LoadMap2();
		}
		if (currentScene->state == SceneStates::CLICK_RANKING)
		{
			LoadRanking();
		}
		if (currentScene->state == SceneStates::CLICK_EXIT)
		{
			state = GameStates::EXIT;
		}
		break;
	case GameStates::MAP_1:
		if (currentScene->state == SceneStates::MAP1_EXIT)
		{
			LoadRanking();
		}
		break;
	case GameStates::MAP_2:
		if (currentScene->state == SceneStates::MAP2_EXIT)
		{
			LoadRanking();
		}
		break;
	case GameStates::RANKING:
		if (currentScene->state == SceneStates::RANKING_EXIT)
		{
			LoadMenu();
		}
		break;
	case GameStates::EXIT:		
		running = false;
		break;
	default:
		break;
	}

	currentScene->Update(input.GetInputs(), input.GetMousePosition());
	Draw();
}

void Game::Draw()
{
	currentScene->Draw();
}

Game::~Game()
{
}
