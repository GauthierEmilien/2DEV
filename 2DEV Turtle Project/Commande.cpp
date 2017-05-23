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
	trim(textCommande);
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
		if (listTextCommande[i].empty()) {
			listTextCommande.erase(listTextCommande.begin() + i);
			i--;
		}
		else {
			listWordCommande.push_back(Word(listTextCommande[i]));
		}
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

inline void Commande::ltrim(std::string & s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

inline void Commande::rtrim(std::string & s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

inline void Commande::trim(std::string & s)
{
	ltrim(s);
	rtrim(s);
}



