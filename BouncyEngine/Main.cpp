
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
	
	linkedList<int>* list = new  linkedList<int>();

	list->insert(1);
	list->insert(2);
	list->insert(3);
	list->insert(14);
	list->insert(15);

	list->printList();
	std::cin.get();
	
	DataStructureEventSystem event(640,480);
	Init_Allegro::initialize();
	Init_Allegro::startTimers();
	event.startGame();

	return 0;
}
