#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Commande.h"

class Console
{
public:
	Console();
	
	bool addCharacter();
	bool eraseCharacter();
	void pressEnter();

	void setEvent(sf::Event pevent);
	void setTextCommandeAffiche();

	sf::Text getTextCommandeAffiche();

private:
	sf::Text textCommandeAffiche;
	sf::Font font;
	sf::Event currentEvent;

	std::string textCommande;
};

