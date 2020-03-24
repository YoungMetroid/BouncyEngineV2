#pragma once
#include "TextWindow.h"
#include "filesUtility.h"
class playerTemplate:TextWindow
{
protected:
	int playerX;
	int playerY;
	const char* name;
	filesUtility *fileReader;
public:
	playerTemplate(const char* name, const char* filePath);
	~playerTemplate();
	void drawRectangle();
	void loadText();
	void setWindowCoordinate(int, int, int, int);
	void setCharacterCoordinates(int, int);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	std::vector<std::vector<std::string>> getText();
};

