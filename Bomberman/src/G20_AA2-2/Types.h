#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

enum class InputKey { QUIT, K_ESC, K_P, K_MOUSE, K_A, K_D, K_W, K_S, K_SPACE, K_LEFT, K_RIGHT, K_UP, K_DOWN, K_CTRL, COUNT };

enum GameStates { MENU, MAP_1, MAP_2, RANKING, EXIT, CURRENT };

enum SceneStates { MENU_RUNNING, CLICK_MAP1, CLICK_MAP2, CLICK_RANKING, CLICK_EXIT, CLICK_SOUND, MAP1_RUNNING, MAP1_ENTER_NAME, MAP1_EXIT, MAP2_RUNNING, MAP2_ENTER_NAME, MAP2_EXIT, RANKING_RUNNING, RANKING_EXIT};

struct VEC2
{
	int x;
	int y;
};


struct Line {
	Line() : a(0), b(0), c(0) {};
	Line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
	int a, b, c;
};

struct RECT {
	int x, y;
	int w, h;

	RECT() {};
	RECT(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {};
	bool checkWallsCollision(RECT _r1, RECT _r2)
	{
		return (((_r1.x - _r2.x) > ((-_r1.w) + 2) && (_r1.x - _r2.x) < (_r1.w - 2)) && ((_r1.y - _r2.y) > ((-_r1.h) + 2) && (_r1.y - _r2.y) < (_r1.h - 2)));
	}
	bool checkGhostCollision(RECT _r1, RECT _r2)
	{
		return (((_r1.x - _r2.x) > ((-_r1.w) + 2) && (_r1.x - _r2.x) < (_r1.w - 2)) && ((_r1.y - _r2.y) > ((-_r1.h) + 2) && (_r1.y - _r2.y) < (_r1.h - 2)));
	}
	bool checkPointsCollision(RECT _r1, RECT _r2)
	{
		return ((_r1.x - _r2.x > -7 && _r1.x - _r2.x < 7) && (_r1.y - _r2.y > -7 && _r1.y - _r2.y < 7));
	}
	//void SetPosition(Vector2 pos) { x = pos.x; y = pos.y; };
};

struct Color {
	unsigned char r, g, b, a;

	Color() {};
	Color(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a) {};
};

using Font = struct {
	std::string id;
	std::string path;
	int size;
};

struct Text {
	std::string id;
	std::string text;
	Color color;
	int w;
	int h;
};