#pragma once
#include "Init_Allegro.h"
#include "Allegro_Dependencies.h"
#include "keyBoardEvent.h"
#include "TextWindow.h"
#include <iostream>
#include <string>


using namespace std;
class Event_System
{
private:
	bool gameLoop;
	static int width;
	static int height;
	int currentEvent;
	int keyPressed = 0;
	
	TextWindow* textWindow;
	
public:
	Event_System(int,int);
	~Event_System();
	void startGame(void);
	void createName(void);
	void mainGame(void);
	
	
};

