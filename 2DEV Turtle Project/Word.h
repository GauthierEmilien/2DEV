#pragma once
#include <iostream>
#include <string>
#include <fstream>


class Word
{
public:
	Word(std::string pvalue);
	~Word();
	int getHasParameter();
	std::string getPorW();
	std::string getValue();
	void setParameter(int p);
	int getParameter();

private:
	std::string wordOrParameter();
	bool isWordExisting();

	std::string value;
	std::string PorW;
	int hasParameter;
	int parameter;
};

