#pragma once
#include "node.h"
#include "../Init_Allegro.h"
#include <thread>
#include <math.h>
template <class T>
class linkedList
{
private:
	node<T>* last;
	node<T>* anchor;
	node<T>* next;
	int counter = 0;
public:

	linkedList();
	void insert(T);
	void printList();
	void bubbleSort();
	void bubbleSortVisual();
	void insertionSort();
	void insertionSortVisual();
	void selectionSortVisual();
	void shellSortVisual();
	void deleteList();
	void resetNext();
	void swapAndDraw(node<T>*, node<T>*, visualBarsInfo*, visualBarsInfo*);
	void swap(node<T>*, node<T>*);
	void moveNode(node<T>*);
	void insertOrdered(node<T>*);
	T getNext();

};
template<class T>
void linkedList<T>::deleteList()
{
	while (anchor != nullptr)
	{
		next = anchor->getNextNode();
		delete anchor;
		anchor = next;
	}
}
template<class T>
void linkedList<T>::resetNext()
{
	next = anchor;
}
template<class T>
T linkedList<T>::getNext()
{
	if (next == nullptr)
	{
		return nullptr;
	}
	T value = next->getData();
	next = next->getNextNode();
	return value;
}
template<class T>
linkedList<T>::linkedList()
{
	anchor = nullptr;
	last = nullptr;
}
template<class T>
void linkedList<T>::insert(T data)
{
	if (anchor == nullptr)
	{
		anchor = new node<T>();
		anchor->setInfo(data);
		last = anchor;
		next = anchor;
		counter++;
	}
	else
	{
		node<T> *newNode = new node<T>();
		newNode->setInfo(data);
		last->setNext(newNode);
		newNode->setPrevious(last);
		last = last->getNextNode();	
		counter++;
	}
}
template<class T>
void linkedList<T>::printList()
{
	 std::cout << std::endl;
	node<T>* tempNode = anchor;
	while (tempNode != nullptr)
	{
		tempNode->printInfo();
		tempNode = tempNode->getNextNode();
	}
	std::cout << "Counter: " << counter << std::endl;
}
template<class T>
void linkedList<T>::bubbleSort()
{
	bool swapped = false;

	for (int currentLoop = 0; currentLoop < counter; currentLoop++)
	{
		node<T>* first = anchor;
		node<T>* second = first->getNode();
		while (second != nullptr)
		{
			if (first->getData() > second->getData())
			{
				swap(first, second);
				swapped = true;
			}
			first = first->getNode();
			second = second->getNode();
		}
		if (!swapped) break;
		swapped = false;
	}
}
template<class T>
void linkedList<T>::bubbleSortVisual()
{
	if (typeid(anchor->getData()) == typeid(visualBarsInfo*))
	{
		bool swapped = false;
		for (int currentLoop = 0; currentLoop < counter; currentLoop++)
		{
			node<T>* first = anchor;
			node<T>* second = first->getNextNode();
			while(second != nullptr)
			{
				visualBarsInfo* firstTemp = static_cast<visualBarsInfo*>(first->getData());
				visualBarsInfo* secondTemp = static_cast<visualBarsInfo*>(second->getData());
				if (firstTemp->getvalue() > secondTemp->getvalue())
				{
					swapAndDraw(first, second, firstTemp, secondTemp);
					//std::this_thread::sleep_for(std::chrono::milliseconds(5));
					swapped = true;
				}
				firstTemp = nullptr;
				secondTemp = nullptr;
				first = first->getNextNode();
				second = second->getNextNode();
			}
			if (!swapped) break;
			swapped = false;
		}
	}
}
template<class T>
void linkedList<T>::insertionSortVisual()
{
	if (typeid(anchor->getData()) == typeid(visualBarsInfo*))
	{
		node<T>* first = anchor;
		node<T>* second = first->getNextNode();
		while (second != nullptr)
		{
			visualBarsInfo* firstTemp = static_cast<visualBarsInfo*>(first->getData());
			visualBarsInfo* secondTemp = static_cast<visualBarsInfo*>(second->getData());
			if (firstTemp->getvalue() > secondTemp->getvalue())
			{
				insertOrdered(second);
			}
			firstTemp = nullptr;
			secondTemp = nullptr;
			first = first->getNextNode();
			second = second->getNextNode();
		}
	}
}
template<class T>
void linkedList<T>::insertionSort()
{
	node<T>* first = anchor;
	node<T>* second = first->getNextNode();
	while (second != nullptr)
	{
		if (first->getData()> second->getData())
		{
			first->setNext(second->getNextNode());
			moveNode(second);
			second = first->getNextNode();
		}
		else 
		{
			first = first->getNextNode();
			second = second->getNextNode();
		}
	}
}
template<class T>
void linkedList<T>::selectionSortVisual()
{
	if (typeid(anchor->getData()) == typeid(visualBarsInfo*))
	{
		bool doSwap = false;
		node<T>* pivot = anchor;
		while (pivot != nullptr)
		{
			node<T>* firstNode = pivot;
			node<T>* currentNode = pivot->getNextNode();
			visualBarsInfo* lowestValue = static_cast<visualBarsInfo*>(firstNode->getData());
			while (currentNode != nullptr)
			{
				visualBarsInfo* currentItem = static_cast<visualBarsInfo*>(currentNode->getData());
				if (lowestValue->getvalue() > currentItem->getvalue())
				{
					firstNode = currentNode;
					lowestValue = static_cast<visualBarsInfo*>(firstNode->getData());
					doSwap = true;
				}
				currentNode = currentNode->getNextNode();
			}
			if (doSwap)
			{
				visualBarsInfo* pivotInfo = static_cast<visualBarsInfo*>(pivot->getData());

				swapAndDraw(pivot, firstNode, pivotInfo, lowestValue);
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
				doSwap = false;
			}
			pivot = pivot->getNextNode();
		}
	}
}
template<class T>
void linkedList<T>::shellSortVisual()
{
	if (typeid(anchor->getData()) == typeid(visualBarsInfo*))
	{
		std::vector<node<T>*> arrayPointers;
		node<T>* temp = anchor;
		while (temp != nullptr)
		{
			arrayPointers.push_back(temp);
			temp = temp->getNextNode();
		}
		bool orderAgain = false;
		double dividen = 3;
		double arraySize = arrayPointers.size()-1;
		double factor = (2.0 / 3.0);
		for (int dif = arraySize * factor; dif > 0; dif = dif * factor)
		{
			for (int limit = arraySize - dif, counter = 0; counter <= limit; counter++)
			{
				node<T>* temp1 = arrayPointers[counter];
				node<T>* temp2 = arrayPointers[counter+dif];
				visualBarsInfo* first = static_cast<visualBarsInfo*>(temp1->getData());
				visualBarsInfo* second = static_cast<visualBarsInfo*>(temp2->getData());
				if (first->getvalue() > second->getvalue())
				{
					swapAndDraw(arrayPointers[counter], arrayPointers[counter + dif], first, second);
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					orderAgain = true;
				}
			}
			float calculate = dif * factor;
			if (orderAgain == true and (calculate) <= 1)
			{
				dif+=1;
			}
			orderAgain = false;
		}


	}
}
template<class T>
void linkedList<T>::swapAndDraw(node<T>* aNode, node<T>* bNode, visualBarsInfo* aInfo, visualBarsInfo* bInfo)
{
	aInfo->clearBar();
	bInfo->clearBar();
	visualBarsInfo* tempInfo = aInfo;
	aInfo = bInfo;
	bInfo = tempInfo;

	int tempPosition = aInfo->xposition;
	aInfo->xposition = bInfo->xposition;
	bInfo->xposition = tempPosition;


	aNode->setInfo(aInfo);
	bNode->setInfo(bInfo);

	aInfo->drawBar();
	bInfo->drawBar();
	al_flip_display();
}
template<class T>
void linkedList<T>::swap(node<T>* aNode, node<T>* bNode)
{
	T temp = aNode->getData();
	aNode->setInfo(bNode->getData());
	bNode->setInfo(temp);
}
template<class T>
void linkedList<T>::insertOrdered(node<T>* node_To_Move)
{
	node<T>* previousNode = node_To_Move->getPreviousNode();
	node<T>* currentNode = node_To_Move;
	while (previousNode != nullptr)
	{
		visualBarsInfo* currentNodeInfo = static_cast<visualBarsInfo*>(currentNode->getData());
		visualBarsInfo* previousNodeInfo = static_cast<visualBarsInfo*>(previousNode->getData());
		if (currentNodeInfo->getvalue() < previousNodeInfo->getvalue())
		{
			swapAndDraw(previousNode, currentNode, previousNodeInfo, currentNodeInfo);
			//std::this_thread::sleep_for(std::chrono::milliseconds(3));
			currentNode = currentNode->getPreviousNode();
			previousNode = previousNode->getPreviousNode();
		}
		else break;
	}
}
template<class T>
void linkedList<T>::moveNode(node<T>* nodeToMoveInfo)
{
	node<T>* currentNode = anchor;
	node<T>* previousNode = anchor;
	if (nodeToMoveInfo->getData() < currentNode->getData())
	{
		nodeToMoveInfo->setNext(anchor);
		anchor = nodeToMoveInfo;
	}
	else
	{
		while (currentNode != nullptr)
		{
			if (currentNode->getNextNode() == nullptr ||
				nodeToMoveInfo->getData() < currentNode->getNextNode()->getData())
			{
				nodeToMoveInfo->setNext(currentNode->getNextNode());
				currentNode->setNext(nodeToMoveInfo);
				break;
			}
			currentNode = currentNode->getNextNode();
		}
	}
}
