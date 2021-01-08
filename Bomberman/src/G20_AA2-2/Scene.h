#pragma once
#include "Types.h"
#include "Renderer.h"

class Scene
{
public:
	SceneStates state;
	Scene();
	virtual void Update(bool * _inputs, VEC2 mousePos) = 0;
	virtual void Draw() = 0;
	~Scene();
};

