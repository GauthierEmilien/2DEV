#include "stdafx.h"
#include "Turtle.h"


Turtle::Turtle()
{
	color = sf::Color(255, 255, 255);
	posX = 500;
	posY = 300;
	angle = 0;
	showing = true;
	painting = true;
	epaisseur = 3;
}


Turtle::~Turtle()
{
}

void Turtle::move(int dist)
{
	float rad = angle * (PI / 180);
	float difX = dist * sin(rad);
	float difY = dist * cos(rad);
	posX += difX;
	posY -= difY;
}

float Turtle::getPosX()
{
	return posX;
}

float Turtle::getPosY()
{
	return posY;
}

void Turtle::setColor(int r, int g, int b)
{
	color = sf::Color(r, g, b);
}

void Turtle::show()
{
	showing = true;
}

void Turtle::hide()
{
	showing = false;
}

void Turtle::penDown()
{
	painting = true;
}

void Turtle::turnRight(int pangle)
{
	angle += pangle;
	if (angle >= 360) {
		angle -= 360;
	}
}

void Turtle::turnLeft(int pangle)
{
	angle -= pangle;
	if (angle < 0) {
		angle += 360;
	}
}

void Turtle::setEpaisseur(int ep)
{
	epaisseur = ep;
}

int Turtle::getEpaisseur()
{
	return epaisseur;
}

void Turtle::center()
{
	posX = 500;
	posY = 300;
	angle = 0;
}

void Turtle::penUp()
{
	painting = false;
}

sf::Color Turtle::getColor()
{
	return color;
}

bool Turtle::getShowing()
{
	return showing;
}

bool Turtle::getPainting()
{
	return painting;
}

sf::CircleShape Turtle::draw()
{
	sf::CircleShape shape(15, 3);
	shape.setFillColor(color);
	shape.setOrigin(15, 15);
	shape.setPosition(posX, posY);
	shape.setRotation(angle);

	return shape;
}

int Turtle::getAngle()
{
	return angle;
}

void Turtle::hexaToColor()
{
}