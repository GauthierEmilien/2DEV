#include "stdafx.h"
#include "testRegex.h"


testRegex::testRegex()
{
}


testRegex::~testRegex()
{
}

vector<string> testRegex::commandeIsOk(string commande, bool & editProc)
{
	vector<string> tabCommande;
	if (allProcedures.size() > 0) {
		string reg("");
		for (int i = 0; i < allProcedures.size(); i++)
		{
			if (!editProc) {
				reg = "(" + allProcedures[i].getName() + ")( [0-9]+){" + to_string(allProcedures[i].getParameters().size()) + "}";
			}
			else {
				reg = "(" + allProcedures[i].getName() + ")(( [0-9]+){" + to_string(allProcedures[i].getParameters().size()) + "}|( ";
				reg.append(createRegexForEditProc() + "){" + to_string(allProcedures[i].getParameters().size()) + "})");
			}
			
			if (regex_match(commande, regex(reg))) {
				string procName;
				smatch pa;
				vector<string> params;
				regex_replace(back_inserter(procName), commande.begin(), commande.end(), regex(reg), "$1");

				//Recupere les parametres
				if (allProcedures[i].getParameters().size() > 0) {
					string ss;
					if (editProc) {
						ss = "( [0-9]+){" + to_string(allProcedures[i].getParameters().size()) + "}|( ";
						ss.append(createRegexForEditProc() + "){" + to_string(allProcedures[i].getParameters().size()) + "}");
					}
					else {
						ss = " [0-9]+";
					}
					while (regex_search(commande, pa, regex(ss))) {
						string p = pa[0];
						p.erase(p.begin(), p.begin() + 1);
						params.push_back(p);
						commande = pa.suffix().str();
					}
				}
				

				//Remplace les noms de parametre par les valeurs parametre
				commande = "";
				for (int j = 0; j < allProcedures[i].getInstructions().size(); j++)
				{
					string inst(allProcedures[i].getInstructions()[j]);
					bool b(true);
					for (int k = 0; k < params.size(); k++) 
					{
						string s("([^ ]*)" + allProcedures[i].getParameters()[k]);
						if (regex_match(inst, regex("([A-Z]{2,} )" + s))) {
							inst = regex_replace(inst, regex(s), params[k]);
							commande += (j > 0) ? " " + inst : inst;
							b = false;
						}
					}
					if (b) {
						commande += (j > 0) ? " " + inst : inst;
					}
				}
			}
		}	
	}
	//REPETE
	if (regex_match(commande, regex("REPETE ([0-9]+) \\[(.+)\\]"))) {	
		string repete, instruction;
		regex_replace(back_inserter(repete), commande.begin(), commande.end(), regex("REPETE ([0-9]+) \\[(.+)\\]"), "$1");
		regex_replace(back_inserter(instruction), commande.begin(), commande.end(), regex("REPETE ([0-9]+) \\[(.+)\\]"), "$2");
		commande = "";
		for (int i = 0; i < stoi(repete); i++)
		{
			commande.append(instruction + " ");
		}
	} //PROCEDURE
	else if (regex_match(commande, regex("POUR ([a-z0-9_]+)( :[a-z0-9_]+)*"))) {
		string name, params;
		smatch m;
		regex_replace(back_inserter(name), commande.begin(), commande.end(), regex("POUR ([a-z0-9_]+)( :[a-z0-9_]+)*"), "$1");
		Procedure proc(name);
		while (regex_search(commande, m, regex(":[a-z0-9_]+"))) {
			proc.addParameter(m[0]);
			commande = m.suffix().str();
		}
		allProcedures.push_back(proc);
		editProc = true;
		tabCommande.push_back("procedure");
	}
	else if (regex_match(commande, regex("^FIN$"))) {
		editProc = false;
	}
	
	std::smatch result;
	regex r;
	if (!editProc) {
		r = "([A-Z]{2,})( [0-9]+| \#[a-f0-9]{6})?";
	}
	else {
		string s("([A-Z]{2,})( ");
		s.append(createRegexForEditProc());
		if (allProcedures[allProcedures.size() - 1].getParameters().size() > 0) {
			s.append("| ");
		}
		s.append("[0-9]+| \#[a-f0-9]{6})?");
		r = s;
	}
	while (regex_search(commande, result, r)) {
		tabCommande.push_back(result[0]);
		commande = result.suffix().str();
	}

	return tabCommande;
}

void testRegex::categoriseCommande(int & i, vector<string> tabCommande, Turtle &turt, int & fraps, Graphics & graph)
{
	if (regex_match(tabCommande[i], regex("(AV|RE|TD|TG) ([0-9]+)"))) {
		string word, param;
		regex_replace(back_inserter(word) ,tabCommande[i].begin(), tabCommande[i].end(), regex("(AV|RE|TD|TG) ([0-9]+)"), "$1");
		regex_replace(back_inserter(param), tabCommande[i].begin(), tabCommande[i].end(), regex("(AV|RE|TD|TG) ([0-9]+)"), "$2");
		if (fraps <= stoi(param)/ turt.getEpaisseur()) {
			commandeWithParam(turt, word, graph);
		}
		else {
			fraps = 0;
			i++;
		}
		
	}
	else if (regex_match(tabCommande[i], regex("FCC \#([a-f0-9]{6})"))) {
		string param;
		regex_replace(back_inserter(param), tabCommande[i].begin(), tabCommande[i].end(), regex("FCC \#([a-f0-9]{6})"), "$1");
		commandeColor(turt, param);
		fraps = 0;
		i++;
	}
	else if (regex_match(tabCommande[i], regex("(LC|BC|VE|CT|MT)"))) {
		commandeWithoutParam(turt, tabCommande[i], graph);
		fraps = 0;
		i++;
	}
	else {
		fraps = 0;
		i++;
	}
}

void testRegex::commandeWithParam(Turtle & turt, string word, Graphics & graph)
{
	if (word == "AV") {
		//grahics here
		if (turt.getPainting()) {
			graph.addPoint(Point(turt.getPosX(), turt.getPosY(), turt.getColor()));
		}
		turt.move(turt.getEpaisseur());
	}
	else if (word == "RE") {
		//graphics here
		if (turt.getPainting()) {
			graph.addPoint(Point(turt.getPosX(), turt.getPosY(), turt.getColor()));
		}
		turt.move(-turt.getEpaisseur());
	}
	else if (word == "TD") {
		turt.turnRight(turt.getEpaisseur());
	}
	else if (word == "TG") {
		turt.turnLeft(turt.getEpaisseur());
	}
}

void testRegex::commandeWithoutParam(Turtle & turt, string word, Graphics & graph)
{
	if (word == "LC") {
		turt.penUp();
	}
	else if (word == "BC") {
		turt.penDown();
	}
	else if (word == "CT") {
		turt.hide();
	}
	else if (word == "MT") {
		turt.show();
	}
	else if (word == "VE") {
		graph.clearPoint();
		turt.center();
	}
}

void testRegex::commandeColor(Turtle & turt, string param)
{
	int R = strtoul(param.substr(0, 2).c_str(), NULL, 16);
	int G = strtoul(param.substr(2, 2).c_str(), NULL, 16);
	int B = strtoul(param.substr(4, 2).c_str(), NULL, 16);
	turt.setColor(R, G, B);
}

void testRegex::addInstruction(vector<string> tabCommande)
{
	for (int i = 0; i < tabCommande.size(); i++)
	{
		allProcedures[allProcedures.size() - 1].addInstruction(tabCommande[i]);
	}
}

string testRegex::createRegexForEditProc()
{
	string s("");
	for (int i = 0; i < allProcedures[allProcedures.size() - 1].getParameters().size(); i++)
	{
		if (i > 0) {
			s.append("| ");
		}
		s.append(allProcedures[allProcedures.size() - 1].getParameters()[i]);
	}
	return s;
}

vector<Procedure> testRegex::allProcedures;