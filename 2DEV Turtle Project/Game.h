#pragma once
#include "SFML\Window.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

class Game
{
public:
	static void Start();

private:
	static void GameMode(sf::Event event);
	static void MainLoop();
	static bool ExitGame();

	enum GamePhase { Uninit, MainMenu, Commande, Animation, Exit };
	static GamePhase gameState;
	static sf::RenderWindow window;
};

