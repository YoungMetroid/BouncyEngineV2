#pragma once
#include "Init_Allegro.h"
class visualBarsInfo
{
public:
	int value;
	int height;
	int xposition;
	int width;
	visualBarsInfo(int, int, int, int);
	ALLEGRO_COLOR color;
	int getvalue();
	void drawBar();
	void clearBar();
	ALLEGRO_COLOR generateRandomColor();
};

