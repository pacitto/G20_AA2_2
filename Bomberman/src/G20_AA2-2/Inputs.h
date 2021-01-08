#pragma once
#include "Types.h"
#include <SDL.h>

class Inputs
{
private:
	SDL_Event event;
public:
	bool keyPressed[(int)InputKey::COUNT];
	bool keyDown[(int)InputKey::COUNT];
	VEC2 mousePos;
	Inputs();
	void UpdateInputs();
	void SetKey(InputKey key, bool value);
	void SetAllFalse();
	bool* GetInputs();
	VEC2 GetMousePosition();
	bool GetKey(InputKey key);
	~Inputs();
};

