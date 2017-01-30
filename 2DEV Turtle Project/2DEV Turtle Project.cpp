// 2DEV projet.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Affichage.h"

using namespace std;

int main()
{
	Affichage fenetre;


	sf::RenderWindow window(sf::VideoMode(1200, 200), "2DEV Projet");

	sf::Text message;

	sf::Font font;
	font.loadFromFile("raidercrusader.ttf");
	message.setFont(font);

	std::string phrase;

	message.setString("ntr");
	message.setCharacterSize(40);
	message.setFillColor(sf::Color::White);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				break;

			case sf::Event::TextEntered:
				if (event.text.unicode < 127 && event.text.unicode > 31) {
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
					phrase.push_back(static_cast<char>(event.text.unicode));
				}
				else if (event.text.unicode == 8) {
					if (phrase.size() > 0)
						phrase.erase(phrase.end() - 1, phrase.end());
				}
				message.setString(phrase);
				break;


			default:
				break;
			}
		}
		window.clear();
		window.draw(message);
		window.display();
	}

	return 0;
}

