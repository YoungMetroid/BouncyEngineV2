#pragma once
#include "Init_Allegro.h"
#include "Allegro_Dependencies.h"
#include "keyBoardEvent.h"
#include "TextWindow.h"
#include <iostream>
#include <string>
#include "playerTemplate.h"


using namespace std;
class Event_System
{
protected:
	bool gameLoop;
	int width;
	int height;
	int currentEvent;
	int keyPressed = 0;
	
	TextWindow* textWindow;
	int eventHandler = 0;
	
	playerTemplate* protagonist;
	std::vector<playerTemplate*> characters;
	
public:
	Event_System(int,int);
	~Event_System();
	void startGame(void);
	void mainGame(void);
	void clearScreen(void);
	void collisionSystem(playerTemplate&);
	void playerMovement();
	void textEvent();
	void drawAllCharacters();
	void characterInteraction(playerTemplate&, int);
};

