#pragma once
#include <vector>

using namespace std;

class Procedure
{
public:
	Procedure(string pname);
	~Procedure();
	string getName();
	vector<string> getInstructions();
	vector<string> getParameters();
	void addParameter(string param);
	void addInstruction(string inst);


private:
	string name;
	vector<string> instructions;
	vector<string> parameters;
};

