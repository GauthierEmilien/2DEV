#include "stdafx.h"
#include "Affichage.h"
#include <iostream>
#include <SFML\Graphics.hpp>


Affichage::Affichage()
{
	window.create(sf::VideoMode(800, 600), "Turtle Project");
	play();
}

void Affichage::play() {
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();

	}
}

