#include "stdafx.h"
#include "Graphics.h"


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}

void Graphics::draw(RenderWindow & fenetre, int ep)
{
	for (int i = 0; i < allPoint.size(); i++)
	{
		RectangleShape p(Vector2f(ep, ep));
		p.setOrigin(ep / 2, ep / 2);
		p.setPosition(allPoint[i].getX(), allPoint[i].getY());
		p.setFillColor(allPoint[i].getColor());
		fenetre.draw(p);
	}
}

void Graphics::addPoint(Point p)
{
	allPoint.push_back(p);
}

void Graphics::clearPoint()
{
	allPoint.clear();
}

void Graphics::back(int nb)
{
	for (int i = 0; i < nb; i++)
	{
		allPoint.pop_back();
	}
}
