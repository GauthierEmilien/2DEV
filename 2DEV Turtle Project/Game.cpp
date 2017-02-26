#include "stdafx.h"
#include "Game.h"




void Game::Start()
{
	window.create(sf::VideoMode(800, 600), "Turtle Project");
	gameState = Game::MainMenu;

	while (!ExitGame())
		MainLoop();

	window.close();
}

void Game::GameMode(sf::Event event)
{
	switch (gameState)
	{
	case Game::MainMenu:
		if (event.type == sf::Event::Closed)
			gameState = Game::Exit;
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
	sf::Event event;
	while (window.pollEvent(event))
	{
		GameMode(event);
	}

	window.clear();
	window.display();
}

bool Game::ExitGame()
{
	return gameState == Game::Exit;
}

Game::GamePhase Game::gameState = MainMenu;
sf::RenderWindow Game::window;