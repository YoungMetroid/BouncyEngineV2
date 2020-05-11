#include "playerTemplate.h"


playerTemplate::playerTemplate(const char* name, const char* filePath):TextWindow(0,0,0,0)
{
	characterX = 0;
	characterY = 0;
	characterWidth = 0;
	characterHeight = 0;
	regularMoveSpeed = 1;
	playerColor = al_map_rgb(50, 50, 50);
	this->name = name;
	fileReader = new filesUtility(filePath);
	fileReader->readFile();
}

playerTemplate::~playerTemplate()
{

}
void playerTemplate::autoSetX(bool left_Right)
{
	characterX += left_Right == true ? regularMoveSpeed : (-1*regularMoveSpeed);
}
void playerTemplate::autoSetY(bool up_Down)
{
	characterY += up_Down == true ? regularMoveSpeed : (-1 * regularMoveSpeed);
}
int playerTemplate::getXPosition()
{
	return characterX;
}
int playerTemplate::getYPosition()
{
	return characterY;
}
int playerTemplate::getPlayerWidth()
{
	return characterWidth;
}
int playerTemplate::getPlayerHeight()
{
	return characterHeight;
}
void playerTemplate::loadText()
{
	fileReader->readFile();
}
void playerTemplate::moveLeft()
{
	characterX--;
}
void playerTemplate::moveRight()
{
	characterX++;
}
void playerTemplate::moveUp()
{
	characterY--;
}
void playerTemplate::moveDown()
{
	characterY++;
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
	this->characterX = x;
	this->characterY = y;
}
void playerTemplate::setCharacterWidth_Height(int width, int height)
{
	characterWidth = width;
	characterHeight = height;
}
void playerTemplate::setX(int newX)
{
	characterX = newX;
}
void playerTemplate::setY(int newY)
{
	characterY = newY;
}
void playerTemplate::drawRectangle()
{
	//Testing the character drawing
	al_draw_filled_rectangle(
		characterX, characterY, 
		characterX+characterWidth, characterY+characterHeight, 
		playerColor);
}
std::vector<std::vector<std::string>> playerTemplate::getText()
{
	return fileReader->allLines;
}