#pragma once
#include "SFML\Window.hpp"
#include <SFML\Graphics.hpp>
#include "Console.h"
#include <iostream>


class Game
{
public:
	static void Start();

private:
	static void GameMode(sf::Event currentEvent);
	static void MainLoop();
	static bool ExitGame();

	static void CommandeEvent(sf::Event currentEvent);

	enum GamePhase { MainMenu, Commande, Animation, Exit };
	static GamePhase gameState;
	static sf::RenderWindow window;
	static Console console;
};

