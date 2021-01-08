#include "Player.h"


Player::Player()
{
}

Player::Player(int _id)
{
	id = _id;
	SetUpPlayer(); 
	
}


void Player::SetUpPlayer()
{
	if(id == 1)
	{
		left = InputKey::K_A; 
		right = InputKey::K_D; 
		up = InputKey::K_W; 
		down = InputKey::K_S; 
		bomb = InputKey::K_SPACE; 

		spriteId == PLAYER1_SPRITESHEET::ID; 
		
	}
	else if (id == 2)
	{
		left = InputKey::K_LEFT; 
		right = InputKey::K_RIGHT;
		up = InputKey::K_UP;
		down = InputKey::K_DOWN;
		bomb = InputKey::K_CTRL; 

		spriteId == PLAYER2_SPRITESHEET::ID;
	}

	animationFrame = { PLAYER_SIZE, 0, PLAYER_SIZE, PLAYER_SIZE };
	SetInitialPos({ 0,0 });
}

void Player::SetLives(int _lives)
{
	lives = _lives; 
}

int Player::GetLives()
{
	return lives;
}

void Player::SetInitialPos(VEC2 _pos)
{
	initialPos = _pos; 
	currentPos = initialPos;
}

VEC2 Player::GetInitialPos()
{
	return initialPos;
}

void Player::Update(bool* _inputs)
{
}

void Player::Draw()
{
	std::cout << spriteId; 
	Renderer::Instance()->PushSprite(spriteId, animationFrame, RECT{currentPos.x * PLAYER_SIZE + OFFSET_X, currentPos.y * PLAYER_SIZE + OFFSET_Y, PLAYER_SIZE, PLAYER_SIZE });
	
}

Player::~Player()
{
}
