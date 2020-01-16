#include "DataStructureEventSystem.h"

DataStructureEventSystem::DataStructureEventSystem(int width, int height) :Event_System(width, height)
{
}
 void DataStructureEventSystem::startGame()
 {
     while (!gameLoop)
     {
         keyBoardEvent::createEvent();
         clearScreen();
         switch (currentEvent)
         {
         case 0:
             if (textWindow == nullptr)
                 textWindow = new TextWindow(0,0, gameWidth - (gameWidth / 4), gameHeight / 3);
             menuEvent();
             break;
         }
     }
 }
 void DataStructureEventSystem::menuEvent()
 {
     if (textWindow->getDoneDrawingText())
     {
         textWindow->getUserInput();
     }
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
        if (keyBoardEvent::returnEvent().timer.source == Init_Allegro::FRAMETIMER)
        {
            textWindow->drawText(10,10);
        }   
        else
        {
            textWindow->drawCurrentText(10,10);
        }
        textWindow->drawUserInput();
        al_flip_display();
         
     }
 }
 void DataStructureEventSystem::clearScreen()
 {
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
         al_clear_to_color(al_map_rgb(0, 0, 0));
     }
 }

