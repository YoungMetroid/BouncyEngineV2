#pragma once
#include "../Event_System.h"
class DataStructureEventSystem:Event_System
{
private:
	enum eventList {menu, sortingSelection};
public:
	DataStructureEventSystem(int width, int height);
	void startGame();
	void menuEvent();
	
};

