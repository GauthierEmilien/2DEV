#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include <vector>
#include "Point.h"

using namespace std;

class Graphics
{
public:
	Graphics();
	~Graphics();
	void draw(RenderWindow &fenetre, int ep);
	void addPoint(Point p);
	void clearPoint();
	void back(int nb);

private:
	vector<Point> allPoint;
};

