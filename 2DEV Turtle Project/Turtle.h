#pragma once
#include "SFML\Graphics.hpp"
#include <math.h>

const double PI = 3.14159265;
using namespace sf;

class Turtle
{
public:
	Turtle();
	~Turtle();
	void move(int dist);


	//GETTER & SETTER
	void setColor(int r, int g, int b);
	void show();
	void hide();
	void penUp();
	void penDown();
	void turnRight(int pangle);
	void turnLeft(int pangle);
	void setEpaisseur(int ep);
	void setPosX(int x);
	void setPosY(int y);

	void center();

	float getPosX();
	float getPosY();
	Color getColor();
	bool getShowing();
	bool getPainting();
	void draw(RenderWindow & window);
	int getAngle();
	int getEpaisseur();

private:
	float posX;
	float posY;
	Color color;
	bool showing;
	bool painting;
	int angle;
	int epaisseur;
	Texture texture;
};

