#include "DataStructureEventSystem.h"

DataStructureEventSystem::DataStructureEventSystem(int width, int height) :Event_System(width, height)
{
}
 void DataStructureEventSystem::startGame()
 {
     srand(time(NULL));
    while (!gameLoop)
    {
        keyBoardEvent::createEvent();
        clearScreen();
        switch (currentEvent)
        {
            case 0:
                if (menuWindow == nullptr)
                    menuWindow = new DataStructureWindow("TextWindow",100,0,0, width - (width / 4), height / 3);
                menuEvent();
                break;
            case 3:
                sortingAlgorithmSelectionMenu();
                break; 
            case 4:
                currentEvent = menuWindow->drawBars(currentEvent,4);
                al_flip_display();
            break;
            case 5:
                currentEvent = menuWindow->drawBars(currentEvent, 5);
                al_flip_display();
            break;
            case 6:
                currentEvent = menuWindow->drawBars(currentEvent, 6);
                al_flip_display();
            break;
            case 7: std::cout << "Shell Sort" << std::endl;
            break;
        }
     }
 }
 void DataStructureEventSystem::sortingAlgorithmSelectionMenu()
 {
     if (windowsList.size() == 0)
     {
        std::cout << "Window1" << std::endl;
        DataStructureWindow* window1 = new DataStructureWindow("Bubble Sort", 4,0, 0, (width/2), height*.25);
        std::cout << "Window2" << std::endl;
        DataStructureWindow* window2 = new DataStructureWindow("Insert Sort", 5, width/2, 0, (width / 2), height*.25);
        std::cout << "Window3" << std::endl;
        DataStructureWindow* window3 = new DataStructureWindow("Selection", 6, 0, height*.25, width/2, height*.25);
        std::cout << "Window4" << std::endl;
        DataStructureWindow* window4 = new DataStructureWindow("Shell Sort", 7, (width / 2), height*.25, width/2, height*.25);
        window1->loadText("Bubble Sort");
        window2->loadText("Insertion Sort");
        window3->loadText("Selection Sort");
        window4->loadText("Shell Sort");
        windowsList.push_back(window1);
        windowsList.push_back(window2);
        windowsList.push_back(window3);
        windowsList.push_back(window4);
     }
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_MOUSE_AXES)
     {
        for (TextWindow* textWindow : windowsList)
        {
            textWindow->mouseInArea(keyBoardEvent::returnEvent().mouse.x,
                keyBoardEvent::returnEvent().mouse.y);
        }
     }
     if(keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
     {
        if (keyBoardEvent::returnEvent().mouse.button == 1)
        {
            for (DataStructureWindow* textWindow : windowsList)
            {
               currentEvent =  textWindow->windowClicked(keyBoardEvent::returnEvent().mouse.x,
                    keyBoardEvent::returnEvent().mouse.y,currentEvent);
            }
        }
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
     if(menuWindow->getDoneDrawingParagraph() and !menuWindow->isLastParagraph() and keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
     { 
         menuWindow->nextTextSignal();
     }
     if (menuWindow->getDoneDrawingAllText())
     {
         if (menuWindow->checkUserInput(menuWindow->number, 1, width))
         {
             currentEvent = 3;
             menuWindow->resetEvent();
         }
     }
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {
        if (keyBoardEvent::returnEvent().timer.source == Init_Allegro::FRAMETIMER)
        {
            menuWindow->drawText(10,10);
        }   
        else
        {
            menuWindow->drawCurrentText(10,10);
        }
        menuWindow->drawUserInput();
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
 void DataStructureEventSystem::createList()
 {
     if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
     {

         al_flip_display();
     }
 }

