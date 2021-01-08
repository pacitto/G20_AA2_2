#pragma once
#include "Types.h"
#include "Constants.h"
#include "Renderer.h"
#include <string>

class Player
{
private:
	int id; 
	int lives;
	VEC2 initialPos;
	VEC2 currentPos;
	InputKey left; 
	InputKey right; 
	InputKey up; 
	InputKey down; 
	InputKey bomb; 
	
	std::string spriteId; 
	RECT animationFrame; 
	
	void SetUpPlayer();
public:
	Player(); 
	Player(int _id);
	void SetLives(int _lives);
	int GetLives();
	void SetInitialPos(VEC2 _pos); 
	VEC2 GetInitialPos(); 

	void Update(bool* _inputs); 
	void Draw(); 
	~Player();
};


