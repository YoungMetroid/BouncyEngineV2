#pragma once
#include "../Event_System.h"
#include "../DataStructureWindow.h"
class DataStructureEventSystem:Event_System
{
private:
	bool draw = false;
	enum eventList {menu, sortingSelection};
	std::vector<DataStructureWindow*> windowsList;
	DataStructureWindow* menuWindow;
public:
	DataStructureEventSystem(int width, int height);
	void clearScreen();
	void menuEvent();
	void sortingAlgorithmSelectionMenu();
	void startGame();
	void createList();
	
	
};

