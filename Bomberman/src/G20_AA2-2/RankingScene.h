#pragma once
#include "Scene.h"

class RankingScene : public Scene
{
public:
	RankingScene();
	void Update(bool* _inputs, VEC2 _mousePos);
	void Draw();
	~RankingScene();
};

