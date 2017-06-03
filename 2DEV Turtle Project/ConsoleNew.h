#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "Turtle.h"
#include "testRegex.h"
#include "Graphics.h"

using namespace std;
using namespace sf;

class ConsoleNew
{
public:
	ConsoleNew(int px, int py);
	~ConsoleNew();
	void play();

private:
	void draw(RenderWindow &fenetre);
	int characterTyping(int gameState, RenderWindow &fenetre);
	int turtleAnimation(int gameState, RenderWindow &fenetre);
	void addCharacter(Event event);
	void eraseCharacter(Event event);
	int verifCommande();

	void prevHistory();
	void nextHistory();

	sf::Text loadFont();
	Font font;
	Color fond;

	const int WINDOW_SIZE_X;
	const int WINDOW_SIZE_Y;

	Text lineText;
	Text lineProc;
	string textCommande;
	vector<string> tabCommande;
	vector<string> commandeHistory;
	int historyIndex;

	int fraps;
	int numComm;
	bool editProc;

	Turtle turt;
	Graphics graph;
};

