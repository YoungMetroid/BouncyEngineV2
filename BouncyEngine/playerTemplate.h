#pragma once
#include "TextWindow.h"
#include "filesUtility.h"
class playerTemplate:TextWindow
{
protected:
	int characterX;
	int characterY;
	int characterWidth;
	int characterHeight;
	int regularMoveSpeed;
	
	ALLEGRO_COLOR playerColor;
	const char* name;
	filesUtility *fileReader;
public:
	playerTemplate(const char* name, const char* filePath);
	~playerTemplate();
	void drawRectangle();
	void loadText();
	void setWindowCoordinate(int, int, int, int);
	void setCharacterCoordinates(int, int);
	void setCharacterWidth_Height(int, int);
	void setX(int);
	void setY(int);
	void autoSetX(bool);
	void autoSetY(bool);
	void setColor(unsigned char r, unsigned char g, unsigned char b);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	int getXPosition();
	int getYPosition();
	int getPlayerWidth();
	int getPlayerHeight();
	std::vector<std::vector<std::string>> getText();
	int facingDirection = 1;
};

