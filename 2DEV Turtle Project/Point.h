#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace sf;

class Point
{
public:
	Point(float px, float py, Color pcolor);
	~Point();
	float getX();
	float getY();
	Color getColor();

private:
	float x;
	float y;
	Color color;
};

