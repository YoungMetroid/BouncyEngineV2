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
	void insertionSort();
	void insertionSortVisual();
	void deleteList();
	void resetNext();
	void swapAndDraw(node<T>*, node<T>*, visualBarsInfo*, visualBarsInfo*);
	void swap(node<T>*, node<T>*);
	void moveNode(node<T>*);
	void moveNodeVisual(node<T>*);
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
		last->nextNode = newNode;
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
		bool repositioned = false;
		for (int currentLoop = 0; currentLoop < counter; currentLoop++)
		{
			node<T>* first = anchor;
			node<T>* second = first->getNextNode();
			while (second != nullptr)
			{
				visualBarsInfo* firstTemp = static_cast<visualBarsInfo*>(first->getData());
				visualBarsInfo* secondTemp = static_cast<visualBarsInfo*>(second->getData());
				if (firstTemp->getvalue() > secondTemp->getvalue())
				{
					// 3->1->4
					// 3->4
					//moveNode(1)
					//result should be 1->3->4
					first->setNext(second->getNextNode());
					moveNode(second);
					repositioned = true;
				}
				firstTemp = nullptr;
				secondTemp = nullptr;
				first = first->getNextNode();
				second = second->getNextNode();
			}
			if (!repositioned) break;
			repositioned = false;
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
			// 3->1->4
			// 3->4
			//moveNode(1)
			//result should be 1->3->4
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
void linkedList<T>::moveNodeVisual(node<T>* node_To_Move)
{
		node<T>* currentNode = anchor;
		node<T>* previousNode = anchor;
		visualBarsInfo* currentNodeInfo = static_cast<visualBarsInfo*>(currentNode->getData());
		visualBarsInfo* nodeToMoveInfo = static_cast<visualBarsInfo*>(node_To_Move->getData());
		if (nodeToMoveInfo->getvalue() < currentNodeInfo->getvalue())
		{
			node_To_Move->setNext(anchor);
			anchor = node_To_Move;
		}
		else
		{
			while (currentNode != nullptr)
			{
				currentNodeInfo = static_cast<visualBarsInfo*>(currentNode->getData());
				if (currentNode->getNextNode() == nullptr || 
					nodeToMoveInfo->getvalue() < 
					static_cast<visualBarsInfo*>(currentNode->getNextNode()->getData())->getvalue())
				{
					nodeToMoveInfo->setNext(currentNode->getNextNode());
					currentNode->setNext(nodeToMoveInfo);
					break;
				}
				currentNode = currentNode->getNextNode();
			}
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

