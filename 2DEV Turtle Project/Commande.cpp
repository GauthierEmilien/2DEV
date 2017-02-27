#include "stdafx.h"
#include "Commande.h"


Commande::Commande(std::string ptextCommande) : textCommande(ptextCommande)
{
	split(' ');
	if (isWordExisting())
		std::cout << "vrai" << std::endl;
	else
		std::cout << "faux" << std::endl;
}

Commande::~Commande()
{
}

void Commande::split(char c)
{
	textCommande += c;
	std::transform(textCommande.begin(), textCommande.end(), textCommande.begin(), ::toupper);
	while (textCommande.size() > 0) {
		int charPos = textCommande.find(c);
		listTextCommande.push_back(textCommande.substr(0, charPos));
		textCommande.erase(0, charPos + 1);
		
	}
}

bool Commande::isWordExisting()
{
	std::ifstream commandeLib("externe/commandes.txt");
	if (commandeLib) {
		std::string mot;
		while (std::getline(commandeLib, mot)) {
			commandeLib >> mot;
			if (mot == listTextCommande[0])
				return true;	
		}
		return false;
	}
	else {
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
		return false;
	}
}

void Commande::wordOrParameter()
{
}
