#pragma once
#include <stdio.h>
#include "Allegro_Dependencies.h"

#define FPS 60
#define frameFPS 30
class Init_Allegro
{
private:
	static bool isInitialized;

public:
	Init_Allegro();
	~Init_Allegro();
	static ALLEGRO_EVENT_QUEUE * EVENTQUEUE;
	static ALLEGRO_KEYBOARD_STATE KEYSTATE;
	static ALLEGRO_DISPLAY * DISPLAY;
	static ALLEGRO_FONT* FONT;
	static enum allEvents { normal, menu, dialog};
	static void initialize(void);
	static void startTimers(void);
	static ALLEGRO_TIMER* TIMER;
	static ALLEGRO_TIMER* FRAMETIMER;
};

