#include "stdafx.h"
#include "Word.h"



Word::Word(std::string pvalue) : value(pvalue)
{
	PorW = wordOrParameter();
	std::cout << PorW << std::endl;
	if (PorW == "word") {
		if (isWordExisting())
			std::cout << "vrai" << std::endl;
		else
			std::cout << "faux" << std::endl;
	}
}

Word::~Word()
{
}

std::string Word::wordOrParameter()
{
	if (value.at(0) >= 'A' && value.at(0) <= 'Z')
		return "word";
	else
		return "parameter";
}

bool Word::isWordExisting()
{
	std::ifstream commandeLib("externe/commandes.txt");
	if (commandeLib) {
		std::string mot;
		while (std::getline(commandeLib, mot)) {
			commandeLib >> mot;
			if (mot == value)
				return true;
		}
		return false;
	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
		return false;
	}
}
