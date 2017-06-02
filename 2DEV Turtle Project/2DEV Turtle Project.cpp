// 2DEV projet.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ConsoleNew.h"

using namespace std;
extern Turtle turtle;

int main()
{
	FreeConsole();
	ConsoleNew console(1000, 600);
	console.play();

	return 0;
}

