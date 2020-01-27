#include <iostream>
#include "linkedList.h"
#include <stdlib.h>
#include <time.h>
#include "../Init_Allegro.h"
#include "DataStructureEventSystem.h"

int main(void)
{
	linkedList<int>* list = new  linkedList<int>();

	list->insert(1);
	list->insert(2);
	list->insert(3);
	list->insert(14);
	list->insert(15);

	srand(time(NULL));

	/*
	for (int counter = 0; counter < 1000; counter++)
	{
		list->insert(rand() % 10000);
	}
	*/
	
	


	//list->printList();
	std::cin.get();
	list->bubbleSort();
	list->printList();
	std::cin.get();	
	DataStructureEventSystem event = DataStructureEventSystem(640, 480);
	Init_Allegro::initialize();
	Init_Allegro::startTimers();
	event.startGame();
	return 0;
}