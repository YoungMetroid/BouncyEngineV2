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