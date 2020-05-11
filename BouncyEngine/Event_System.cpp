#include "Event_System.h"


Event_System::Event_System(int width,int height):gameLoop(false),currentEvent(0)
{
	textWindow = nullptr;
	this->width = width;
	this->height = height;
	protagonist = new playerTemplate("Felipe", "Narration.txt");
	protagonist->setColor(50, 100, 50);
	protagonist->setCharacterCoordinates(50, 50);
	protagonist->setCharacterWidth_Height(20, 20);

	for (int i = 1; i < 20; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			playerTemplate* pt = new playerTemplate("Stranger", "");
			short red = rand() % 255 + 1;
			short green = rand() % 255 + 1;;
			short blue = rand() % 255 + 1;;
			pt->setColor(red, green, blue);
			pt->setCharacterCoordinates((100*i) , (100*j));
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
		keyBoardEvent::UpdateKeys(true);
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
		keyBoardEvent::UpdateKeys(false);
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
	{
		switch (eventHandler)
		{
			case 0:
				playerMovement();
				drawAllCharacters();
				break;
			case 1:
				drawAllCharacters();
				//textEvent();
				break;
			case 2:
				break;
				
			default:
				break;
		}
		
		al_flip_display();
	}
}
void Event_System::characterInteraction(playerTemplate& player, int facingDirection)
{
	//Check Left Side Collision
	
	if (protagonist->facingDirection == 1 and protagonist->getXPosition() >= player.getXPosition() + player.getPlayerWidth() and
		protagonist->getXPosition() <= player.getXPosition() + player.getPlayerWidth() + 10 and
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
	{
		//protagonist->autoSetX(true);
		std::cout << "In interaction area" << std::endl;
	}

	//Check Right Side Collision
/*
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
*/
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
void Event_System::playerMovement()
{
	if (keyBoardEvent::keys[ALLEGRO_KEY_A])
	{
		protagonist->moveLeft();
		protagonist->facingDirection = 1;
	}
	if (keyBoardEvent::keys[ALLEGRO_KEY_S])
	{
		protagonist->moveDown();
		protagonist->facingDirection = 2;
	}
	if (keyBoardEvent::keys[ALLEGRO_KEY_D])
	{
		protagonist->moveRight();
		protagonist->facingDirection = 3;
	}
	if (keyBoardEvent::keys[ALLEGRO_KEY_W])
	{
		protagonist->moveUp();
		protagonist->facingDirection = 4;
	}
	if (keyBoardEvent::keys[ALLEGRO_KEY_J])
	{
		for (playerTemplate* player : characters)
		characterInteraction(*player,protagonist->facingDirection);
	}
}
void Event_System::textEvent()
{
	if (textWindow == nullptr)
	{
		textWindow = new TextWindow(0,540,1280,180);
		textWindow->setTextObject(protagonist->getText());
	}

	if (textWindow->getDoneDrawingParagraph() and 
		!textWindow->isLastParagraph())
	{
 		textWindow->nextTextSignal();
	}
	if (textWindow->isLastParagraph())
	{
		
	}
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
	{
		if (keyBoardEvent::returnEvent().timer.source == Init_Allegro::FRAMETIMER)
		{
			textWindow->drawWindow();
			textWindow->drawText(10, 10);
		}
		else
		{
			textWindow->drawWindow();
			textWindow->drawCurrentText(10, 10);
		}
	}

}
void Event_System::drawAllCharacters()
{
	protagonist->drawRectangle();
	for (playerTemplate* player : characters)
	{
		collisionSystem(*player);
		player->drawRectangle();
	}
}