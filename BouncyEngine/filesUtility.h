#pragma once
#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>

class myException
{
	virtual const char* what() const throw()
	{
		return "Unable to open file";
	}
};
class filesUtility
{
protected:

private:
	const char* filePath;
	std::ifstream file;

public:
	std::vector< std::vector<std::string>> allLines;
	filesUtility();
	filesUtility(const char* filePath);
	void readFile();

};

