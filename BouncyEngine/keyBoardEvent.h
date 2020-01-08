#pragma once
#include "Init_Allegro.h"
#include <iostream>

class keyBoardEvent
{
private:
	static ALLEGRO_EVENT event;
public:

	static void createEvent();
	static bool isEnteredPressed();
	static ALLEGRO_EVENT returnEvent();
	keyBoardEvent();
	~keyBoardEvent();
};

