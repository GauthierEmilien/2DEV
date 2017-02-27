#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Word.h"

class Commande
{
public:
	Commande(std::string ptextCommande);
	~Commande();
	void split(char c);

private:

	std::string textCommande;
	std::vector<std::string> listTextCommande;
	std::vector<Word> listWordCommande;
};

