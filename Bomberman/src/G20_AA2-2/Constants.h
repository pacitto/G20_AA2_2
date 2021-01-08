#pragma once

const int SCREEN_HEIGHT = 704;
const int SCREEN_WIDTH = 720;
const int OFFSET_Y = 128;
const int OFFSET_X = 48;
const int HEIGHT = 11;
const int WIDTH = 13;
const int PLAYER_SIZE = 48; 

namespace GAME
{
	const std::string BACKGROUND_PATH = "../../res/img/bgGame.jpg";
	const std::string BACKGROUND_ID = "BackgroundGame";	
}

namespace ITEMS_SPRITESHEET
{
	const int HEIGHT = 96;
	const int WIDTH = 144;
	const int SIZE = 48;	
	const std::string TEXT = "";	
	const Color COLOR = Color(255, 255, 255, 0);
	const std::string PATH = "../../res/img/items.png";
	const std::string ID = "ItemsSpritesheet";
}

namespace PLAYER1_SPRITESHEET
{
	const int HEIGHT = 192;
	const int WIDTH = 144;		
	const std::string TEXT = "";
	const Color COLOR = Color(255, 255, 255, 0);
	const std::string PATH = "../../res/img/player1.png";
	const std::string ID = "Player1Spritesheet";
}

namespace PLAYER2_SPRITESHEET
{
	const int HEIGHT = 192;
	const int WIDTH = 144;	
	const std::string TEXT = "";
	const Color COLOR = Color(255, 255, 255, 0);
	const std::string PATH = "../../res/img/player2.png";	
	const std::string ID = "Player2Spritesheet";
}

namespace EXPLOSION_SPRITESHEET
{
	const int HEIGHT = 336;
	const int WIDTH = 192;
	const int SIZE = 48;
	const std::string TEXT = "";
	const Color COLOR = Color(255, 255, 255, 0);
	const std::string PATH = "../../res/img/explosion.png";
	const std::string ID = "ExplosionSpritesheet";	

}

namespace MAIN_FONT
{
	const std::string ID = "MainFont";
	const std::string PATH = "../../res/ttf/saiyan.ttf";
	const int SIZE = 30;
}

namespace MAP1_BUTTON
{
	const std::string ID = "Map1Button";
	const std::string TEXT = "MAP ONE";
	const Color COLOR = Color(255, 0, 0, 255);
	const std::string HOVER_ID = "Map1ButtonHover";
	const Color HOVER_COLOR = Color(255, 0, 255, 255);
	const int W = 275;
	const int H = 100;
	const int X = 223;
	const int Y = 50;
}

namespace MAP2_BUTTON
{
	const std::string ID = "Map2Button";
	const std::string TEXT = "MAP TWO";
	const Color COLOR = Color(255, 0, 0, 255);
	const std::string HOVER_ID = "Map2ButtonHover";
	const Color HOVER_COLOR = Color(255, 0, 255, 255);
	const int W = 275;
	const int H = 100;
	const int X = 223;
	const int Y = 175;
}

namespace RANKING_BUTTON
{
	const std::string ID = "RankingButton";
	const std::string TEXT = "RANKING";
	const Color COLOR = Color(255, 0, 0, 255);
	const std::string HOVER_ID = "RankingButtonHover";
	const Color HOVER_COLOR = Color(255, 0, 255, 255);
	const int W = 275;
	const int H = 100;
	const int X = 223;
	const int Y = 300;
}

namespace EXIT_BUTTON
{
	const std::string ID = "ExitButton";
	const std::string TEXT = "EXIT";
	const Color COLOR = Color(255, 0, 0, 255);
	const std::string HOVER_ID = "ExitButtonHover";
	const Color HOVER_COLOR = Color(255, 0, 255, 255);
	const int W = 120;
	const int H = 80;
	const int X = 300;
	const int Y = 575;
}

namespace SOUND_BUTTON
{
	const std::string ID = "SoundButton";
	const std::string TEXT = "SOUND ON OFF";
	const Color COLOR = Color(255, 0, 0, 255);
	const std::string HOVER_ID = "SoundButtonHover";
	const Color HOVER_COLOR = Color(255, 0, 255, 255);
	const int W = 280;
	const int H = 80;
	const int X = 220;
	const int Y = 475;
}