#include "stdafx.h"
#include "Console.h"


Console::Console()
{
	font.loadFromFile("PixelFont.ttf");

	textCommandeAffiche.setFont(font);
	textCommandeAffiche.setCharacterSize(20);
	textCommandeAffiche.setFillColor(sf::Color::White);
	textCommandeAffiche.setString("? ");
	textCommandeAffiche.setPosition(0,22);
}

bool Console::addCharacter()
{
	if (currentEvent.text.unicode < 127 && currentEvent.text.unicode > 31) {
		std::cout << "ASCII character typed: " << static_cast<char>(currentEvent.text.unicode) << std::endl;
		textCommande.push_back(static_cast<char>(currentEvent.text.unicode));
		return true;
	}
	return false;
}

void Console::eraseCharacter()
{
	if (currentEvent.text.unicode == 8) {
		if (textCommande.size() > 0)
			textCommande.erase(textCommande.end() - 1, textCommande.end());
	}
}

void Console::setEvent(sf::Event pevent)
{
	currentEvent = pevent;
}

void Console::setTextCommandeAffiche()
{
	textCommandeAffiche.setString("? " + textCommande);
}

sf::Text Console::getTextCommandeAffiche()
{
	return textCommandeAffiche;
}



