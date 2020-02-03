#include "DataStructureWindow.h"


DataStructureWindow::DataStructureWindow(const char * name, int sortingAlgorithmID, int x1, int y1 ,int x2, int y2)
	:TextWindow( x1,  y1,  x2, y2)
{
	this->sortingAlgorithmID = sortingAlgorithmID;
	this->algorithmName = name;
	this->currentCreatedElement = 0;
	this->currentXStart = 0;
}

int DataStructureWindow::getID()
{
	return sortingAlgorithmID;
}

std::string DataStructureWindow::getName()
{
	return algorithmName;
}

int DataStructureWindow::windowClicked(int x, int y, int currentEvent)
{
	if (mouseInArea(x, y))
	{
		return sortingAlgorithmID;
	}
	return currentEvent;
}

bool DataStructureWindow::checkUserInput(short userDesiredInput, long lowerLimit, long upperLimit)
{
	std::string userInput = getUserInput();
	switch (userDesiredInput)
	{
		case 0:
			bool flag = std::all_of(userInput.begin(), userInput.end(), ::isdigit);
			if (flag  && userInput.size() > 0 )
			{
				elementsToCreate = std::stoi(userInput);
				if (elementsToCreate > lowerLimit && elementsToCreate <= upperLimit)
				{		
					calculatedWidth = floor((double)upperLimit / (double)elementsToCreate);
					return true;
				}
			}
			return false;
			break;
	}
	return false;
}

int DataStructureWindow::getElementsToGenerate()
{
	return elementsToCreate;
}

int DataStructureWindow::drawBars(int currentEvent, int sortingAlgorithm)
{
	if (doneSorting == true and keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_KEY_UP)
	{
		list->deleteList();
		currentCreatedElement = 0;
		currentXStart = 0;
		doneSorting = false;
		//elementsToCreate = 0;
		return 3;
	}
	if (keyBoardEvent::returnEvent().type == ALLEGRO_EVENT_TIMER)
		if (currentCreatedElement < elementsToCreate)
		{
			int randomNumber = rand() % 1000 + 1;
			int calculatedHeight = normalize(1, 1000, 0, Init_Allegro::height, randomNumber);
			visualBarsInfo* vbi = new visualBarsInfo(randomNumber, currentXStart, calculatedWidth, calculatedHeight);
			list->insert(vbi);
			drawList();

			currentCreatedElement++;
			currentXStart += calculatedWidth;
		}
		else if(currentCreatedElement >= elementsToCreate and doneSorting == false)
		{
			switch (sortingAlgorithm)
			{
			case 4:
				drawList();
				list->bubbleSortVisual();
				break;
			case 5:
				drawList();
				list->insertionSortVisual();
				break;
			case 6: 
				drawList();
				list->selectionSortVisual();
				break;
			default:
				list->bubbleSortVisual();
				break;
			}
			doneSorting = true;
		}
		else if (doneSorting == true)	
		{
			visualBarsInfo* currentBar;
			while (currentBar = list->getNext())
			{
				currentBar->drawBar();
			}
			list->resetNext();
		}
		return currentEvent;
}
int DataStructureWindow::normalize(int min, int max, int normalizedMin, int normalizedMax, int value)
{
	int operation1 = normalizedMax - normalizedMin;
	int operation2 = value - min;
	int operation3 = max - min;
	double operation4 = ((double)operation2 / (double)operation3);
	int operation5 = floor(operation1 * operation4) + (double)min;
	return operation5;
}
void DataStructureWindow::drawList()
{
	visualBarsInfo* currentBar;
	while (currentBar = list->getNext())
	{
		currentBar->drawBar();
	}
	list->resetNext();
}
 
