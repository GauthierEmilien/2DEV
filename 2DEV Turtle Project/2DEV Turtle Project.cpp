// 2DEV projet.cpp�: d�finit le point d'entr�e pour l'application console.
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

