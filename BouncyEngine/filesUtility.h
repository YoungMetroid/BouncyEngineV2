#pragma once
#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include <fstream>

class myException:public _exception
{
public:const char* what() const throw()
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
	std::ofstream createFile;

public:
	std::vector< std::vector<std::string>> allLines;
	filesUtility();
	filesUtility(const char* filePath);
	void readFile();

};

