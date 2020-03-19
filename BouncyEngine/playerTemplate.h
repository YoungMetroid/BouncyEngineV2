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

	
};

