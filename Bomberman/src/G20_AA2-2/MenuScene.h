#pragma once
#include "Scene.h"
#include "Button.h"

class MenuScene : public Scene
{
private:
	Button map1Button;
	Button map2Button;
	Button rankingButton;
	Button exitButton;
	Button soundButton;
public:
	MenuScene();
	void Update(bool* _inputs, VEC2 _mousePos);
	void Draw();
	~MenuScene();
};

