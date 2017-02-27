#pragma once
#include <iostream>
#include <string>
#include <fstream>


class Word
{
public:
	Word(std::string pvalue);
	~Word();

private:
	std::string wordOrParameter();
	bool isWordExisting();

	std::string value;
	std::string PorW;
	bool hasParameter;
};

