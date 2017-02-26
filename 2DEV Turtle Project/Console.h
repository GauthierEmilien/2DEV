#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Console
{
public:
	Console();
	
	bool addCharacter();
	void eraseCharacter();

	void setEvent(sf::Event pevent);
	void setTextCommandeAffiche();

	sf::Text getTextCommandeAffiche();

private:
	sf::Text textCommandeAffiche;
	sf::Font font;
	sf::Event currentEvent;

	std::string textCommande;
};

