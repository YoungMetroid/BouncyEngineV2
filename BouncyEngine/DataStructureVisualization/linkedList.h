#pragma once
#include "node.h"
template <class T>
class linkedList
{
private:
	node<T>* last;
	node<T>* anchor;
	int counter = 0;
public:

	linkedList();
	void insert(T);
	void printList();
	void bubbleSort();

};

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
	node<T>* tempNode = anchor;
	while (tempNode != nullptr)
	{
		tempNode->printInfo();
		tempNode = tempNode->getNode();
	}

	anchor->printInfo();
	std::cout << "Counter: " << counter << std::endl;
}
template<class T>
void linkedList<T>::bubbleSort()
{
	for (int i = 0; i < counter; i++)
	{
		node<T>* first = anchor;
		node<T>* second = first->getNode();
		for (int j = i + 1; j < counter; j++)
		{
			if (first->getData() > second->getData())
			{
				int temp = first->getData();
				first->setInfo(second->getData());
				second->setInfo(temp);
			}
			first = first->getNode();
			second = second->getNode();
		}
	}
}




