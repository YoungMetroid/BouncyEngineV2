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
        std::cout << "Window1" << std::endl;
        TextWindow* window1 = new TextWindow(0, 0, width/2, height*.25);
        std::cout << "Window2" << std::endl;
        TextWindow* window2 = new TextWindow(width/2, 0, (width / 2), height*.25);
        std::cout << "Window3" << std::endl;
        TextWindow* window3 = new TextWindow(0, height*.25, width/2, height*.25);
        std::cout << "Window4" << std::endl;
        TextWindow* window4 = new TextWindow((width / 2), height*.25, width/2, height*.25);
        window1->loadText("Bubble Sort");
        window2->loadText("Insertion Sort");
        window3->loadText("Selection Sort");
        window4->loadText("Sheel Sort");
        windowsList.push_back(window1);
        windowsList.push_back(window2);
        windowsList.push_back(window3);
        windowsList.push_back(window4);
     }
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_MOUSE_AXES)
     {
         
     }

     
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
         for (TextWindow *textWindow : windowsList)
         {
             textWindow->drawWindow();
             textWindow->drawInstantText();
         }

        al_flip_display();
     }

 }
 void DataStructureEventSystem::menuEvent()
 {
     if(textWindow->getDoneDrawingParagraph() && !textWindow->isLastParagraph() &&keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
     { 
         textWindow->nextTextSignal();
     }
     if (textWindow->getDoneDrawingAllText())
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

