#include "playerTemplate.h"


playerTemplate::playerTemplate(const char* name, const char* filePath):TextWindow(0,0,0,0)
{
	playerX = 0;
	playerY = 0;
	playerColor = al_map_rgb(50, 50, 50);
	this->name = name;
	fileReader = new filesUtility(filePath);
}

playerTemplate::~playerTemplate()
{

}

void playerTemplate::loadText()
{
	fileReader->readFile();
}
void playerTemplate::moveLeft()
{
	playerX--;
}
void playerTemplate::moveRight()
{
	playerX++;
}
void playerTemplate::moveUp()
{
	playerY--;
}
void playerTemplate::moveDown()
{
	playerY++;
}
void playerTemplate::setColor(unsigned char red, unsigned char green, unsigned char blue)
{
	playerColor = al_map_rgb(red, green, blue);
}
void  playerTemplate::setWindowCoordinate(int x1, int x2, int y1, int y2)
{
	this->startingXCoordinate = x1;
	this->endingXCoordinate = x2;
	this->startingYCoordinate = y1;
	this->endingYCoordinate = y2;
}
void playerTemplate::setCharacterCoordinates(int x, int y)
{
	this->playerX = x;
	this->playerY = y;
}
void playerTemplate::drawRectangle()
{
	//Testing the character drawing
	al_draw_filled_rectangle(
		playerX, playerY, 
		playerX+100, playerY+100, 
		playerColor);
}
std::vector<std::vector<std::string>> playerTemplate::getText()
{
	return fileReader->allLines;
}