#include "playerTemplate.h"


playerTemplate::playerTemplate(const char* filePath):TextWindow(0,0,0,0)
{
	playerX = 0;
	playerY = 0;
	fileReader = new filesUtility(filePath);
}

playerTemplate::~playerTemplate()
{

}

void playerTemplate::loadText()
{
	fileReader->readFile();
}
void  playerTemplate::setWindowCoordinate(int x1, int x2, int y1, int y2)
{
	this->startingXCoordinate = x1;
	this->endingXCoordinate = x2;
	this->startingYCoordinate = y1;
	this->endingYCoordinate = y2;
}
std::vector<std::vector<std::string>> playerTemplate::getText()
{
	return fileReader->allLines;
}