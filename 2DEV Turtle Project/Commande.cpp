#include "stdafx.h"
#include "Commande.h"


Commande::Commande(std::string ptextCommande) : textCommande(ptextCommande)
{
	split(' ');
	Word m(listTextCommande[0]);
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

