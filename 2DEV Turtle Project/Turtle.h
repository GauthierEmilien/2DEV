#pragma once
#include "SFML\Graphics.hpp"
#include <math.h>

const double PI = 3.14159265;

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
	int getEpaisseur();

	void center();

	float getPosX();
	float getPosY();
	sf::Color getColor();
	bool getShowing();
	bool getPainting();
	sf::CircleShape draw();
	int getAngle();


private:
	void hexaToColor();
	float posX;
	float posY;
	sf::Color color;
	bool showing;
	bool painting;
	int angle;
	int epaisseur;
};

