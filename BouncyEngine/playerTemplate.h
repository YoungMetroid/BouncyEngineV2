#pragma once
#include "TextWindow.h"
#include "filesUtility.h"
class playerTemplate:TextWindow
{
protected:
	int playerX;
	int playerY;
	filesUtility *fileReader;
public:
	playerTemplate(const char* filePath);
	~playerTemplate();
	void loadText();
	void setWindowCoordinate(int, int, int, int);
	std::vector<std::vector<std::string>> getText();

	
};

