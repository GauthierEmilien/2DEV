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
	static void categoriseCommande(int &i, vector<string> tabCommande, Turtle &turt, int &fraps, Graphics &graph);
	static void commandeWithParam(Turtle &turt, string word, Graphics &graph);
	static void commandeWithoutParam(Turtle &turt, string word, Graphics &graph);
	static void commandeColor(Turtle &turt, string param);
	static void addInstruction(vector<string> tabCommande);
	static string createRegexForEditProc();

	static vector<Procedure> allProcedures;
};

