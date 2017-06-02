#include "stdafx.h"
#include "Procedure.h"


Procedure::Procedure(string pname) : name(pname)
{
}


Procedure::~Procedure()
{
}

string Procedure::getName()
{
	return name;
}

vector<string> Procedure::getInstructions()
{
	return instructions;
}

vector<string> Procedure::getParameters()
{
	return parameters;
}

void Procedure::addParameter(string param)
{
	parameters.push_back(param);
}

void Procedure::addInstruction(string inst)
{
	instructions.push_back(inst);
}
