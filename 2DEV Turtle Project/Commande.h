#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include "Word.h"
#include "SFML\Graphics.hpp"

class Commande
{
public:
	Commande(std::string ptextCommande);
	~Commande();
	void split(char c);
	void createWords();
	void ifWordHasParameter();

private:
	
	inline void ltrim(std::string &s);
	inline void rtrim(std::string &s);
	inline void trim(std::string &s);
	std::string resultToShow;
	std::string textCommande;
	std::vector<std::string> listTextCommande;
	std::vector<Word> listWordCommande;
};

