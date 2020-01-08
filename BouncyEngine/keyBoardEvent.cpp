#include "keyBoardEvent.h"

ALLEGRO_EVENT keyBoardEvent::event;

keyBoardEvent::keyBoardEvent()
{
}


keyBoardEvent::~keyBoardEvent()
{
}


void keyBoardEvent::createEvent()
{
	al_wait_for_event(Init_Allegro::EVENTQUEUE, &event);
}

ALLEGRO_EVENT keyBoardEvent::returnEvent()
{
	return event;
}

bool keyBoardEvent::isEnteredPressed()
{
	if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
	{
		std::cout << "Pressed !! " << std::endl;
		return true;
	}
	return false;
}
