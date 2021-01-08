#include "MenuScene.h"

MenuScene::MenuScene()
{
	state = SceneStates::MENU_RUNNING;
	map1Button = Button{ MAP1_BUTTON::ID, MAP1_BUTTON::HOVER_ID, MAP1_BUTTON::X, MAP1_BUTTON::Y, MAP1_BUTTON::W, MAP1_BUTTON::H };
	map2Button = Button{ MAP2_BUTTON::ID, MAP2_BUTTON::HOVER_ID, MAP2_BUTTON::X, MAP2_BUTTON::Y, MAP2_BUTTON::W, MAP2_BUTTON::H };
	rankingButton = Button{ RANKING_BUTTON::ID, RANKING_BUTTON::HOVER_ID, RANKING_BUTTON::X, RANKING_BUTTON::Y, RANKING_BUTTON::W, RANKING_BUTTON::H };
	exitButton = Button{ EXIT_BUTTON::ID, EXIT_BUTTON::HOVER_ID, EXIT_BUTTON::X, EXIT_BUTTON::Y, EXIT_BUTTON::W, EXIT_BUTTON::H };
	soundButton = Button{ SOUND_BUTTON::ID, SOUND_BUTTON::HOVER_ID, SOUND_BUTTON::X, SOUND_BUTTON::Y, SOUND_BUTTON::W, SOUND_BUTTON::H };
}

void MenuScene::Update(bool* _inputs, VEC2 _mousePos)
{
	switch (state)
	{
	case MENU_RUNNING:
		map1Button.Update(_inputs[(int)InputKey::K_MOUSE], _mousePos);
		map2Button.Update(_inputs[(int)InputKey::K_MOUSE], _mousePos);
		rankingButton.Update(_inputs[(int)InputKey::K_MOUSE], _mousePos);
		exitButton.Update(_inputs[(int)InputKey::K_MOUSE], _mousePos);
		soundButton.Update(_inputs[(int)InputKey::K_MOUSE], _mousePos);
		if (map1Button.isPressed) state = SceneStates::CLICK_MAP1;
		if (map2Button.isPressed) state = SceneStates::CLICK_MAP2;
		//if (rankingButton.isPressed) state = SceneStates::CLICK_RANKING;
		if (exitButton.isPressed) state = SceneStates::CLICK_EXIT;
		//if (soundButton.isPressed) state = SceneStates::CLICK_SOUND;
		break;
	case CLICK_MAP1:
		break;
	case CLICK_MAP2:
		break;
	case CLICK_RANKING:
		break;
	case CLICK_SOUND:
		break;
	case CLICK_EXIT:
		break;
	default:
		break;
	}
}

void MenuScene::Draw()
{
	Renderer::Instance()->Clear();
	Renderer::Instance()->SetRenderDrawColor(0, 0, 0);
	map1Button.Draw();
	map2Button.Draw();
	rankingButton.Draw();
	exitButton.Draw();
	soundButton.Draw();
	Renderer::Instance()->Render();
}

MenuScene::~MenuScene()
{
}
