#include "stdafx.h"
#include "Game.h"


void Game::Start()
{
	window.create(sf::VideoMode(800, 600), "Turtle Project");
	gameState = Game::MainMenu;
	Console console;

	while (!ExitGame())
		MainLoop();

	window.close();
}

void Game::GameMode(sf::Event currentEvent)
{
	switch (gameState)
	{
	case Game::MainMenu:
		CommandeEvent(currentEvent);
		break;
	case Game::Commande:
		break;
	case Game::Animation:
		break;
	default:
		break;
	}
}

void Game::MainLoop()
{
	sf::Event currentEvent;
	while (window.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
			gameState = Game::Exit;

		GameMode(currentEvent);
	}

	window.clear();
	window.draw(console.getTextCommandeAffiche());
	window.display();
}

bool Game::ExitGame()
{
	return gameState == Game::Exit;
}

void Game::CommandeEvent(sf::Event currentEvent)
{
	switch (currentEvent.type)
	{
	case sf::Event::TextEntered:
		console.setEvent(currentEvent);
		if (!console.addCharacter())
			if (!console.eraseCharacter())
				console.pressEnter();
		console.setTextCommandeAffiche();
		break;

	default:
		break;
	}
}



Game::GamePhase Game::gameState = MainMenu;
sf::RenderWindow Game::window;
Console Game::console;