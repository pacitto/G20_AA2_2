#include "Inputs.h"

Inputs::Inputs()
{
	mousePos.x = 0;
	mousePos.y = 0;
}

void Inputs::UpdateInputs()
{
	SetAllFalse();

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			keyPressed[(int)InputKey::QUIT] = true;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) keyPressed[(int)InputKey::K_ESC] = true;
			if (event.key.keysym.sym == 'p') keyPressed[(int)InputKey::K_P] = true;
			if (event.key.keysym.sym == 'a') keyPressed[(int)InputKey::K_A] = true;
			if (event.key.keysym.sym == 'd') keyPressed[(int)InputKey::K_D] = true;
			if (event.key.keysym.sym == 'w') keyPressed[(int)InputKey::K_W] = true;
			if (event.key.keysym.sym == 's') keyPressed[(int)InputKey::K_S] = true;
			if (event.key.keysym.sym == SDLK_SPACE) keyPressed[(int)InputKey::K_SPACE] = true;
			if (event.key.keysym.sym == SDLK_LEFT) keyPressed[(int)InputKey::K_LEFT] = true;
			if (event.key.keysym.sym == SDLK_RIGHT) keyPressed[(int)InputKey::K_RIGHT] = true;
			if (event.key.keysym.sym == SDLK_UP) keyPressed[(int)InputKey::K_UP] = true;
			if (event.key.keysym.sym == SDLK_DOWN) keyPressed[(int)InputKey::K_DOWN] = true;
			if (event.key.keysym.sym == SDLK_RCTRL) keyPressed[(int)InputKey::K_CTRL] = true;

			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE) keyPressed[(int)InputKey::K_ESC] = false;
			if (event.key.keysym.sym == 'p') keyPressed[(int)InputKey::K_P] = false;
			if (event.key.keysym.sym == 'a') keyPressed[(int)InputKey::K_A] = false;
			if (event.key.keysym.sym == 'd') keyPressed[(int)InputKey::K_D] = false;
			if (event.key.keysym.sym == 'w') keyPressed[(int)InputKey::K_W] = false;
			if (event.key.keysym.sym == 's') keyPressed[(int)InputKey::K_S] = false;
			if (event.key.keysym.sym == SDLK_SPACE) keyPressed[(int)InputKey::K_SPACE] = false;
			if (event.key.keysym.sym == SDLK_LEFT) keyPressed[(int)InputKey::K_LEFT] = false;
			if (event.key.keysym.sym == SDLK_RIGHT) keyPressed[(int)InputKey::K_RIGHT] = false;
			if (event.key.keysym.sym == SDLK_UP) keyPressed[(int)InputKey::K_UP] = false;
			if (event.key.keysym.sym == SDLK_DOWN) keyPressed[(int)InputKey::K_DOWN] = false;
			if (event.key.keysym.sym == SDLK_RCTRL) keyPressed[(int)InputKey::K_CTRL] = false;
			break;
		case SDL_MOUSEBUTTONUP:
			keyPressed[(int)InputKey::K_MOUSE] = true;
			break;
		case SDL_MOUSEMOTION:
			mousePos.x = event.motion.x;
			mousePos.y = event.motion.y;
			break;
		default:;
		}
	}
}

void Inputs::SetKey(InputKey key, bool value)
{
	if (!keyPressed[(int)key])
	{
		keyDown[(int)key] = value;
	}
	else
	{
		keyDown[(int)key] = false;
	}
	keyPressed[(int)key] = value;
}

void Inputs::SetAllFalse()
{
	for (int i = 0; i < (int)InputKey::COUNT; i++)
	{
		keyPressed[i] = false;
	}
}

bool* Inputs::GetInputs()
{
	return keyPressed;
}

VEC2 Inputs::GetMousePosition()
{
	return mousePos;
}

bool Inputs::GetKey(InputKey key)
{
	return keyPressed[(int)key];
}

Inputs::~Inputs()
{
}
