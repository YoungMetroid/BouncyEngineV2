#include "visualBarsInfo.h"


visualBarsInfo::visualBarsInfo(int value, int xposition,  int width, int height)
{
	this->value = value;
	this->xposition = xposition;
	this->width = width;
	this->height = height;
	color = generateRandomColor();
}

int visualBarsInfo::getvalue()
{
	return value;
}

void visualBarsInfo::drawBar()
{
	al_draw_filled_rectangle(xposition, Init_Allegro::height - height,
		xposition + width, Init_Allegro::height, color);
}

void visualBarsInfo::clearBar()
{
	al_draw_filled_rectangle(xposition, Init_Allegro::height - height,
		xposition + width, Init_Allegro::height, al_map_rgb(0, 0, 0));
}

ALLEGRO_COLOR visualBarsInfo::generateRandomColor()
{
	unsigned char red = rand() % 255 + 1;
	unsigned char green = rand() % 255 + 1;;
	short blue = rand() % 255 + 1;;
	ALLEGRO_COLOR clr = al_map_rgb(red, green, blue);
	return clr;
}