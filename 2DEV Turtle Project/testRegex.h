#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <cctype>
#include <functional>
#include "Turtle.h"
#include "Graphics.h"
#include "Point.h"
#include "Procedure.h"


using namespace std;

class testRegex
{
public:
	testRegex();
	~testRegex();
	static vector<string> commandeIsOk(string commande, bool &editProc);
	static vector<string> prepareCommande(string commande, bool editProc);
	static void categoriseCommande(int &i, vector<string> tabCommande, Turtle &turt, int &fraps, Graphics &graph, Color &fond);
	static void commandeWithParam(Turtle &turt, string word, Graphics &graph, int i);
	static void commandeWithoutParam(Turtle &turt, string word, Graphics &graph);
	static void commandeColor(Turtle &turt, string param, string word, Color &fond);
	static void addInstruction(vector<string> tabCommande);
	static string createRegexForEditProc();
	static string checkIfProcedure(string commande, bool editProc);
	static vector<string> getParameterFromProc(string reg, string commande, bool editProc, int i);
	static string replaceParameterByValue(string commande, int i, vector<string> params);
	static void find_and_replace(string &source, string const& find, string const& replace);
	static string testRepete(string commande);
	static void testProcedure(string commande);
	static void prepareHistory();

	static vector<Procedure> allProcedures;
	static vector<int> nbPtsHistory;
	static vector<int> posXHistory;
	static vector<int> posYHistory;
	static int numCommandeHistory;
};

