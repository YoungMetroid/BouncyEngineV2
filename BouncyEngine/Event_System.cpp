#include "Event_System.h"


Event_System::Event_System(int width,int height):gameLoop(false),currentEvent(0)
{
	textWindow = nullptr;
	this->width = width;
	this->height = height;
}

Event_System::~Event_System()
{
}

void Event_System::startGame(void)
{
	while(!gameLoop)
	{
		keyBoardEvent::createEvent();
		
		switch (currentEvent)
		{
			case 0: 
				mainGame();
				break;
			case 1:
				textWindow->getUserInput();
				if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					textWindow->drawWindow();
					textWindow->drawUserInput();
					al_flip_display();
				}
				currentEvent = textWindow->getEvent();
				if (currentEvent == Init_Allegro::allEvents::normal)
 					delete textWindow;
				break;
			case 2:
				if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
				{
					keyPressed = keyBoardEvent::returnEvent().keyboard.keycode;
				}
				if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
				{
					if (keyBoardEvent::returnEvent().timer.source == Init_Allegro::FRAMETIMER)
					{	
						currentEvent = textWindow->getEvent();
						if (currentEvent == Init_Allegro::allEvents::normal)
							{
							keyPressed = 0;
						}
					}
					al_clear_to_color(al_map_rgb(0, 0, 0));
					//textWindow->drawText();
					al_flip_display();
				}
				break;
		}
	}
}
void Event_System::createName(void)
{
	textWindow->drawWindow();
	textWindow->getUserInput();
}
void Event_System::mainGame(void)
{
	if(keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
		switch (keyBoardEvent::returnEvent().keyboard.keycode)
		{
			case ALLEGRO_KEY_ESCAPE:
				gameLoop = true;
				break;
			case ALLEGRO_KEY_ENTER:
				currentEvent = Init_Allegro::allEvents::menu;
				textWindow = new TextWindow(gameWidth / 4, gameHeight/4, gameWidth - (gameWidth / 4), gameHeight/3);
				break;
			case ALLEGRO_KEY_A:
				currentEvent = Init_Allegro::allEvents::dialog;
				textWindow = new TextWindow(gameWidth / 4, gameHeight / 4, gameWidth - (gameWidth / 4), gameHeight / 3);
				textWindow->setEvent(currentEvent);
				break;
			default:
				std::cout << "No Input" << std::endl;
				break;
		}
}
