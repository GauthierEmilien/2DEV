#pragma once

#include <SFML\Graphics.hpp>

class Affichage
{
public:
	Affichage();
	void play();

private:
	sf::RenderWindow window;
	sf::Font font;
	sf::Event event;
};

