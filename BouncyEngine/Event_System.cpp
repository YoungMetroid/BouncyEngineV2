#include "Event_System.h"


Event_System::Event_System(int width,int height):gameLoop(false),currentEvent(0)
{
	textWindow = nullptr;
	this->width = width;
	this->height = height;
	protagonist = new playerTemplate("Felipe", "");
	protagonist->setColor(50, 100, 50);
	protagonist->setCharacterCoordinates(50, 50);
	protagonist->setCharacterWidth_Height(20, 20);

	for (int i = 1; i < 30; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			playerTemplate* pt = new playerTemplate("Stranger", "");
			short red = rand() % 255 + 1;
			short green = rand() % 255 + 1;;
			short blue = rand() % 255 + 1;;
			pt->setColor(red, green, blue);
			pt->setCharacterCoordinates((50*i) , (50*j));
			pt->setCharacterWidth_Height(20, 20);
			characters.push_back(pt);
		}
	}
	


	

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
			collisionSystem(*player);
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
void Event_System::collisionSystem(playerTemplate& player)
{
	//Check Left Side Collision
	if (protagonist->getXPosition() == player.getXPosition() + player.getPlayerWidth() and 
		((
			protagonist->getYPosition() >= player.getYPosition() and 
			protagonist->getYPosition() <= player.getYPosition()+ player.getPlayerHeight()
		) 
		or
		(
			protagonist->getYPosition() + protagonist->getPlayerHeight() >= player.getYPosition() and 
			protagonist->getYPosition() + protagonist->getPlayerHeight() <= player.getYPosition() + player.getPlayerHeight()
		))
	   )
		protagonist->autoSetX(true);
	//Check Right Side Collision

	if (protagonist->getXPosition() + protagonist->getPlayerWidth() == player.getXPosition() and
		((
			protagonist->getYPosition() >= player.getYPosition() and
			protagonist->getYPosition() <= player.getYPosition() + player.getPlayerHeight()
			)
			or
			(
				protagonist->getYPosition() + protagonist->getPlayerHeight() >= player.getYPosition() and
				protagonist->getYPosition() + protagonist->getPlayerHeight() <= player.getYPosition() + player.getPlayerHeight()
				))
		)
		protagonist->autoSetX(false);

	//Check Top Side Collision
	if (protagonist->getYPosition() == player.getYPosition() + player.getPlayerHeight() and
		((
			protagonist->getXPosition() >= player.getXPosition() and
			protagonist->getXPosition() <= player.getXPosition() + player.getPlayerWidth()
			)
			or
			(
				protagonist->getXPosition() + protagonist->getPlayerWidth() >= player.getXPosition() and
				protagonist->getXPosition() + protagonist->getPlayerWidth() <= player.getXPosition() + player.getPlayerWidth()
				))
		)
		protagonist->autoSetY(true);
	//Check Bottom Side Collision

	if (protagonist->getYPosition() + protagonist->getPlayerHeight() == player.getYPosition() and
		((
			protagonist->getXPosition() >= player.getXPosition() and
			protagonist->getXPosition() <= player.getXPosition() + player.getPlayerWidth()
			)
			or
			(
				protagonist->getXPosition() + protagonist->getPlayerWidth() >= player.getXPosition() and
				protagonist->getXPosition() + protagonist->getPlayerWidth() <= player.getXPosition() + player.getPlayerWidth()
				))
		)
		protagonist->autoSetY(false);
}
