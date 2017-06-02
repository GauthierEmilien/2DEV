#include "stdafx.h"
#include "ConsoleNew.h"


ConsoleNew::ConsoleNew(int px, int py) : WINDOW_SIZE_X(px), WINDOW_SIZE_Y(py)
{
}


ConsoleNew::~ConsoleNew()
{
}

void ConsoleNew::play()
{
	RenderWindow fenetre(VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32), "Turtle Project");
	fenetre.setFramerateLimit(120);

	lineText = loadFont();
	lineProc = loadFont();
	lineProc.setString("");

	historyIndex = 0;
	int gameState = 0;
	fraps = 0;
	numComm = 0;
	editProc = false;


	while (fenetre.isOpen()) {

		switch (gameState)
		{
		case 0:
			gameState = characterTyping(gameState, fenetre);
			break;
		case 1:
			gameState = turtleAnimation(gameState, fenetre);
			break;
		default:
			break;
		}

	}
}

int ConsoleNew::characterTyping(int gameState, RenderWindow &fenetre)
{	
	Event event;

	while (fenetre.pollEvent(event)) {
		switch (event.type)
		{
		case Event::Closed:
			gameState = -1;
			fenetre.close();
			break;

		case Event::TextEntered:
			addCharacter(event);
			if (!editProc) {
				lineText.setString("?" + textCommande);
			}
			else {
				lineText.setString(">" + textCommande);
			}
			break;

		case Event::KeyPressed:
			switch (event.key.code)
			{
			case Keyboard::Return:
				gameState = verifCommande();
				break;

			case Keyboard::BackSpace:
				eraseCharacter(event);
				if (!editProc) {
					lineText.setString("?" + textCommande);
				}
				else {
					lineText.setString(">" + textCommande);
				}
				break;

			case Keyboard::Up:
				prevHistory();
				if (!editProc) {
					lineText.setString("?" + textCommande);
				}
				else {
					lineText.setString(">" + textCommande);
				}
				break;
			case Keyboard::Down:
				nextHistory();
				if (!editProc) {
					lineText.setString("?" + textCommande);
				}
				else {
					lineText.setString(">" + textCommande);
				}
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
	}

	draw(fenetre);

	return gameState;
}

int ConsoleNew::turtleAnimation(int gameState, RenderWindow & fenetre)
{
	Event event;
	while (fenetre.pollEvent(event)) {
		switch (event.type)
		{
		case Event::Closed:
			gameState = -1;
			fenetre.close();
			break;
		default:
			break;
		}
	}

	fraps += 1;
	testRegex::categoriseCommande(numComm, tabCommande, turt, fraps, graph);

	if (numComm == tabCommande.size()) {
		textCommande = "";
		lineText.setString("? ");
		numComm = 0;
		gameState = 0;
	}

	draw(fenetre);

	return gameState;
}

void ConsoleNew::draw(RenderWindow & fenetre)
{
	fenetre.clear(Color::Black);
	graph.draw(fenetre, turt.getEpaisseur());
	if (turt.getShowing()) {
		fenetre.draw(turt.draw());
	}
	if (editProc) {
		fenetre.draw(lineProc);
	}
	fenetre.draw(lineText);
	fenetre.display();
}

void ConsoleNew::addCharacter(Event event)
{
	if (event.text.unicode < 127 && event.text.unicode > 31) {
		textCommande.push_back(static_cast<char>(event.text.unicode));
	}
}

void ConsoleNew::eraseCharacter(Event event)
{
	if (textCommande.size() > 0)
		textCommande.erase(textCommande.end() - 1, textCommande.end());
}

int ConsoleNew::verifCommande()
{
	commandeHistory.push_back(textCommande);
	historyIndex = commandeHistory.size();
	tabCommande = testRegex::commandeIsOk(textCommande, editProc);
	if (editProc && tabCommande[0] != "procedure") {
		testRegex::addInstruction(tabCommande);
		tabCommande.clear();
		textCommande = "";
	}
	if (tabCommande.size() > 0 && tabCommande[0] == "procedure") {
		lineProc.setPosition(0, 560);
		lineProc.setString(lineText.getString());
	}
	
	return (tabCommande.size() > 0) ? 1 : 0;
	
}

void ConsoleNew::prevHistory()
{
	if (commandeHistory.size() > 0 && historyIndex > 0) {
		historyIndex--;
		textCommande = commandeHistory[historyIndex];
	}
	
}

void ConsoleNew::nextHistory()
{
	if (commandeHistory.size() > 0) {
		if (historyIndex < commandeHistory.size() - 1) {
			historyIndex++;
			textCommande = commandeHistory[historyIndex];
		}
		else if (historyIndex == commandeHistory.size() - 1) {
			historyIndex++;
			textCommande = "";
		}
	}
}

sf::Text ConsoleNew::loadFont()
{
	Text text;
	font.loadFromFile("PixelFont.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(Color::Cyan);
	text.setPosition(0, 585);
	text.setString("?");

	return text;
}
