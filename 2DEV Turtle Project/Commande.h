#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

	std::string resultToShow;
	std::string textCommande;
	std::vector<std::string> listTextCommande;
	std::vector<Word> listWordCommande;
};

