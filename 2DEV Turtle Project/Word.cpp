#include "stdafx.h"
#include "Word.h"



Word::Word(std::string pvalue) : value(pvalue)
{
	parameter = 0;
	PorW = wordOrParameter();
	if (PorW == "word") {
		if (isWordExisting())
			std::cout << "vrai" << std::endl;
		else
			std::cout << "faux" << std::endl;
	}
	//std::cout << value << " " << PorW << " " << hasParameter << std::endl;
}

Word::~Word()
{
}



std::string Word::wordOrParameter()
{
	if (value.at(0) >= 'A' && value.at(0) <= 'Z')
		return "word";
	else {
		hasParameter = 0;
		return "parameter";
	}
		
}

bool Word::isWordExisting()
{
	std::ifstream commandeLib("externe/commandes.txt");
	if (commandeLib) {
		std::string mot;
		while (std::getline(commandeLib, mot)) {
			commandeLib >> mot;
			commandeLib >> hasParameter;
			if (mot == value)
				return true;
		}
		hasParameter = 0;
		return false;
	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
		return false;
	}
}


int Word::getHasParameter()
{
	return hasParameter;
}

std::string Word::getPorW()
{
	return PorW;
}

std::string Word::getValue()
{
	return value;
}

void Word::setParameter(int p)
{
	parameter = p;
}

int Word::getParameter()
{
	return parameter;
}
