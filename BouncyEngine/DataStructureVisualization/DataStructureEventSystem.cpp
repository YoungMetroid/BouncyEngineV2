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
         case 3:
             sortingAlgorithmSelectionMenu();
             break;

         }
     }
 }
 void DataStructureEventSystem::sortingAlgorithmSelectionMenu()
 {
     if (windowsList.size() == 0)
     {
        TextWindow* window1 = new TextWindow(0, 0, (width / 2) - width * .05, height / 8);
        TextWindow* window2 = new TextWindow((width / 2) + width * .05, 0, width, height / 8);
        TextWindow* window3 = new TextWindow(0, height / 8, (width / 2) - width * .05, height / 4);
        TextWindow* window4 = new TextWindow((width / 2) + width * .05, height / 8, width, height / 4);
        windowsList.push_back(window1);
        windowsList.push_back(window2);
        windowsList.push_back(window3);
        windowsList.push_back(window4);
     }
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
         windowsList[0]->drawWindow();
         windowsList[1]->drawWindow();
         windowsList[2]->drawWindow();
         windowsList[3]->drawWindow();
         al_flip_display();
     }

 }
 void DataStructureEventSystem::menuEvent()
 {
     if (textWindow->getDoneDrawingText())
     {
         textWindow->getUserInput();
         if (textWindow->getEvent() != -1)
         {
             currentEvent = textWindow->getEvent();
             textWindow->resetEvent();
         }
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

