#pragma once
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

class Commande
{
public:
	Commande(std::string ptextCommande);
	~Commande();
	void split(char c);

private:
	bool isWordExisting();
	void wordOrParameter();

	std::string textCommande;
	std::vector<std::string> listTextCommande;
};

