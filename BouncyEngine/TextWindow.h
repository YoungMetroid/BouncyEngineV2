#pragma once
#include "Window.h"
#include "Allegro_Dependencies.h"
#include "keyBoardEvent.h"
#include "Init_Allegro.h"
#include <iostream>
#include <vector>

class TextWindow:Window
{
private:
	std::string name;
	int currentEvent = 1;
	int columncount = 0;
	
	int rowCount = 0;
	int paragraghCount = 0;

	std::string currentText;
	std::vector<std::string> printText;
	std::string textLine1;
	std::string textLine2;
	
	std::vector<std::vector<std::string>> text;
public:
	TextWindow(int startingXCoordinate, int startingYCoordinate,
		int endingXCoordinate, int endingYCoordinate);
	~TextWindow();
	void getUserInput();
	void drawText(int keyPressed);
	void drawUserInput();
	void drawWindow();
	int getEvent();
	void setEvent(int event);
	void setTextObject(std::vector<std::vector<std::string>>characterText);
	std::vector<std::vector<std::string>> getTextObject();


	
};