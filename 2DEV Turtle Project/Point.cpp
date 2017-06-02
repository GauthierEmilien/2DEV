#include "stdafx.h"
#include "Point.h"


Point::Point(float px, float py, Color pcolor) : x(px), y(py), color(pcolor)
{
}


Point::~Point()
{
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

Color Point::getColor()
{
	return color;
}
