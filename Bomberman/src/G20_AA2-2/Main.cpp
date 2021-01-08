#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

int main(int, char* [])
{
	Game game;
	while (game.running)
	{
		game.RunGame();
	}

	Renderer::Instance()->~Renderer();
	return 0;
}