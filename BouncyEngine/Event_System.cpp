#include "Event_System.h"


Event_System::Event_System(int width,int height):gameLoop(false),currentEvent(0)
{
	textWindow = nullptr;
	this->width = width;
	this->height = height;
	protagonist = new playerTemplate("Felipe", "");
	protagonist->setCharacterCoordinates(50, 50);
	//characters.push_back(protagonist);
}

Event_System::~Event_System()
{
}

void Event_System::startGame(void)
{
	
	while(!gameLoop)
	{
		keyBoardEvent::createEvent();
		clearScreen();
		switch (currentEvent)
		{
			case 0: 
				mainGame();
				break;
		}
	}
}
void Event_System::mainGame(void)
{
	if(keyBoardEvent::returnEvent().type ==ALLEGRO_EVENT_MOUSE_AXES)
	{	
	}
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (keyBoardEvent::returnEvent().keyboard.keycode)
		{
		case ALLEGRO_KEY_A:
			keys[0] = true;
			break;
		case ALLEGRO_KEY_S:
			keys[1] = true;
			break;
		case ALLEGRO_KEY_D:
			keys[2] = true;
			break;
		case ALLEGRO_KEY_W:
			keys[3] = true;
			break;
		}
	}
	if(keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
		switch (keyBoardEvent::returnEvent().keyboard.keycode)
		{
			case ALLEGRO_KEY_ESCAPE:
				gameLoop = true;
				break;
			case ALLEGRO_KEY_A:
				keys[0] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[1] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[2] = false;
				break;
			case ALLEGRO_KEY_W:
				keys[3] = false;
				break;
		}

	

	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
	{
		if (keys[0])
			protagonist->moveLeft();
		if (keys[1])
			protagonist->moveDown();
		if (keys[2])
			protagonist->moveRight();
		if (keys[3])
			protagonist->moveUp();

		protagonist->drawRectangle();
		for (playerTemplate* player : characters)
		{
			player->drawRectangle();
		}
		al_flip_display();
	}
}
void Event_System::clearScreen()
{
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
}
