#pragma once
#include "Window.h"
#include "Allegro_Dependencies.h"
#include "keyBoardEvent.h"
#include "Init_Allegro.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

class TextWindow:public Window
{
private:
	bool doneDrawingAllText = false;
	bool doneDrawingParagragh = false;
	bool lastParagragh = false;
	bool wait = false;
	
	int currentEvent = -1;
	int columncount = 0;

	short red = 255;
	short green = 255;
	short blue = 255;
	
	int rowCount = 0;
	int paragraghCount = 0;

	float imageWidth = 0;
	float imageHeight = 0;


	std::string userInput;
	

	ALLEGRO_BITMAP* windowFrame;
	std::string loadedText;
	std::string currentText;
	std::vector<std::string> printText;
	std::string textLine1;
	std::string textLine2;
	
	std::vector<std::vector<std::string>> text;
public:
	TextWindow(int startingXCoordinate, int startingYCoordinate,
		int endingXCoordinate, int endingYCoordinate);
	~TextWindow();
	std::string getUserInput();
	bool getDoneDrawingParagraph();
	bool isLastParagraph();
	void drawText(int,int);
	void drawCurrentText(int,int);
	void drawUserInput();
	void drawWindow();
	void drawInstantText();
	void nextTextSignal();
	int getEvent();
	void loadImage(const char*);
	void loadText(std::string);
	void loadParagraphs(std::vector<std::vector<std::string>>);
	bool mouseInArea(int,int);
	void resetEvent();
	void setEvent(int event);
	
	void setTextObject(std::vector<std::vector<std::string>>characterText);
	std::vector<std::vector<std::string>> getTextObject();


	
};