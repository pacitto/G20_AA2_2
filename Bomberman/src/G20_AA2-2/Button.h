#pragma once
#include "Types.h"
#include "Renderer.h"
class Button
{
private:
	std::string normalId;
	std::string hoverId;
public:
	bool isPressed;
	std::string buttonId;
	RECT buttonRect;
	Button();
	Button(std::string _id, std::string _hoverId, int _x, int _y, int _w, int _h);
	void Update(bool _mousePressed, VEC2 _mousePosition);
	void Draw();
	bool checkHover(VEC2 _mousePos);
	~Button();
};

