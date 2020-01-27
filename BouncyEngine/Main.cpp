
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>

#include "Init_Allegro.h";
#include "DataStructureVisualization/DataStructureEventSystem.h";
#include "DataStructureVisualization/linkedList.h"

int main()
{
	char buff[FILENAME_MAX];
	GetModuleFileName(NULL, buff, FILENAME_MAX);
	std::string::size_type pos = std::string(buff).find_last_of("\\/");
	std::cout << std::string(buff).substr(0, pos);
	
	linkedList<visualBarsInfo*>* list = new linkedList<visualBarsInfo*>();

	list->insert(new visualBarsInfo(5,2,3,4));
	list->insert(new visualBarsInfo(4,2,3,4));
	list->insert(new visualBarsInfo(3,2,3,4));
	list->insert(new visualBarsInfo(1,2,3,4));
	


	
	
	DataStructureEventSystem event(1280,720);
	Init_Allegro::initialize(1280,720);
	Init_Allegro::startTimers();
	event.startGame();

	return 0;
}
