#pragma once
#include "Init_Allegro.h"
#include <iostream>

class keyBoardEvent
{
private:
	static ALLEGRO_EVENT event;
public:
	static bool keys[100];
	static void createEvent();
	static bool isEnteredPressed();
	static ALLEGRO_EVENT returnEvent();
	static void UpdateKeys(bool);
	keyBoardEvent();
	~keyBoardEvent();
};

