#pragma once
#include "../Event_System.h"
class DataStructureEventSystem:Event_System
{
private:
	bool draw = false;
	enum eventList {menu, sortingSelection};
	std::vector<TextWindow*> windowsList;
public:
	DataStructureEventSystem(int width, int height);
	void clearScreen();
	void menuEvent();
	void sortingAlgorithmSelectionMenu();
	void startGame();
	
	
};

