// 2DEV projet.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Game.h"

using namespace std;

int main()
{
	FreeConsole();
	Game::Start();

	return 0;
}

