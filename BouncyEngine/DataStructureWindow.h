#pragma once
#include "TextWindow.h"
#include "visualBarsInfo.h"
#include "DataStructureVisualization/linkedList.h"
#include <math.h>
class DataStructureWindow :
	public TextWindow
{
 
private:
	int sortingAlgorithmID;
	int elementsToCreate;
	int currentCreatedElement;
	std::string algorithmName;
	int currentXStart;
	int currentXEnd;
	int calculatedWidth;
	linkedList<visualBarsInfo*>* list = new linkedList<visualBarsInfo*>();

public:
	DataStructureWindow(const char*,int,int,int,int,int); 
	enum userInputType { number, decimalNumber, string };
	int getID();
	int windowClicked(int,int, int current);
	int getElementsToGenerate();
	int normalize(int min, int max, int normalizedMin, int normalizedMax, int value);
	bool checkUserInput(short,long lowerLimit, long upperLimit);
	void drawBars();
	std::string getName();
};

