#pragma once
#include "node.h"
#include "../Init_Allegro.h"
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
	void resetNext();
	void swap(node<T>*, node<T>*);
	T getNext();

};
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
	next = next->getNode();
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
		last->nextNode = newNode;
		last = last->getNode();	
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
		tempNode = tempNode->getNode();
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
				//int temp = first->getData();
				//first->setInfo(second->getData());
				//second->setInfo(temp);
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
		for (int i = 0; i < counter; i++)
		{
			node<T>* first = anchor;
			node<T>* second = first->getNode();
			visualBarsInfo* firstTemp = static_cast<visualBarsInfo*>(first->getData());
			visualBarsInfo* secondTemp = static_cast<visualBarsInfo*>(second->getData());
			for (int j = i + 1; j < counter; j++)
			{
				if (firstTemp->getvalue() > secondTemp->getvalue())
				{
					firstTemp->clearBar();
					secondTemp->clearBar();

					visualBarsInfo* third = firstTemp;
					firstTemp = secondTemp;
					secondTemp = third;

					int value = firstTemp->xposition;
					firstTemp->xposition = secondTemp->xposition;
					secondTemp->xposition = value;
					
					first->setInfo(firstTemp);
					second->setInfo(secondTemp);

					
					firstTemp->drawBar();
					secondTemp->drawBar();
					al_flip_display();
				}
				first = first->getNode();
				firstTemp = static_cast<visualBarsInfo*>(first->getData());
				second = second->getNode();
				if (second == nullptr) return;
				secondTemp = static_cast<visualBarsInfo*>(second->getData());
			}
		}
	}
}
template<class T>
void linkedList<T>::swap(node<T>*a, node<T>* b)
{
	node<T> *temp = b->getNode();
	b->nextNode = a;
	a->nextNode = temp;
}




