#pragma once
#include "Scene.h"
#include "HUD.h"
#include "Player.h"
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"
#include <sstream> 
#include <string>
//#include <vector>

class Map1Scene : public Scene
{
private:
	HUD *hud;
	Player *player1;
	Player *player2;
	std::string backgroundId;
	RECT backgroundRect;
	char** map;
	void InitMap();
	void ReadConfig();

public:
	Map1Scene();
	void Update(bool* _inputs, VEC2 _mousePos);
	void Draw();
	~Map1Scene();
};