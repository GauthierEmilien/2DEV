#include "stdafx.h"
#include "Commande.h"


Commande::Commande(std::string ptextCommande) : textCommande(ptextCommande)
{
	split(' ');
	createWords();
	ifWordHasParameter();
	//to string
	for (int i = 0; i < listWordCommande.size(); i++) {
		std::cout << listWordCommande[i].getValue() << " " << listWordCommande[i].getPorW() << " "
			<< listWordCommande[i].getHasParameter() << " " << listWordCommande[i].getParameter() << std::endl;
	}
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

void Commande::createWords()
{
	for (int i = 0; i < listTextCommande.size(); i++) {
		listWordCommande.push_back(Word(listTextCommande[i]));
	}
}

void Commande::ifWordHasParameter()
{
	for (int i = 0; i < listWordCommande.size(); i++) {
		if (listWordCommande[i].getHasParameter() != 0) {
			try {
				if (listWordCommande.at(i + 1).getPorW() == "parameter") {
					listWordCommande[i].setParameter(std::stoi(listWordCommande[i + 1].getValue()));
				}
			}
			catch(const std::out_of_range& e) {
				std::cout << "No parameter detected after " << listWordCommande[i].getValue() << std::endl;
				
			}
		}
	}
}



