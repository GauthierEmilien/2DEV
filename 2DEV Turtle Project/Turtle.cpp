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
	ConvexShape shape;
	shape.setPointCount(3);
	shape.setPoint(0, Vector2f(12.5, 0));
	shape.setPoint(1, Vector2f(5, 15));
	shape.setPoint(2, Vector2f(20, 15));

	CircleShape triangle(7.5, 3);
	triangle.setOrigin(-4.5, 1);
	CircleShape circle(8);
	circle.setOrigin(-4, -7);

	RenderTexture renderTexture;
	renderTexture.create(31, 40);
	renderTexture.clear(Color::Transparent);
	renderTexture.draw(triangle);
	renderTexture.draw(circle);
	renderTexture.display();

	texture = Texture(renderTexture.getTexture());

	
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

void Turtle::setPosX(int x)
{
	posX = x;
}

void Turtle::setPosY(int y)
{
	posY = y;
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

Color Turtle::getColor()
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

void Turtle::draw(RenderWindow & window)
{
	Sprite sprite = Sprite(texture);
	sprite.setColor(color);
	sprite.setPosition(posX, posY);
	sprite.setRotation(angle);
	sprite.setOrigin(12.5, 12.5);

	window.draw(sprite);
}

int Turtle::getAngle()
{
	return angle;
}