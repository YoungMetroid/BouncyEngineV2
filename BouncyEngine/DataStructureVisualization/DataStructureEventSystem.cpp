#include "DataStructureEventSystem.h"

 DataStructureEventSystem::DataStructureEventSystem(int width,int height):Event_System(width,height)
{
     textWindow = new TextWindow(gameWidth / 4, gameHeight / 4, gameWidth - (gameWidth / 4), gameHeight / 3);
}
 void DataStructureEventSystem::startGame()
 {
     while (!gameLoop)
     {
         keyBoardEvent::createEvent();
         switch (currentEvent)
         {
         case 0: 
             menuEvent();
             break;
         }
     }
 }
 void DataStructureEventSystem::menuEvent()
 {
     //textWindow->drawText(0);
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
         if (keyBoardEvent::returnEvent().timer.source == Init_Allegro::FRAMETIMER)
         {
            //currentEvent = textWindow->getEvent();
             al_clear_to_color(al_map_rgb(0, 0, 0));
             textWindow->drawText(0);
             al_flip_display();
            
         }
         
     }
 }

