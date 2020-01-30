#pragma once
#include <iostream>
template<class T>
class node
{
private:
	T data;
public:
	node();
	node<T> *nextNode;
	node<T>* previousNode;
	T getData();
	void setNext(node<T>*);
	void setInfo(T);
	void printInfo();
	node<T>* getNextNode();
	node<T>* getPreviousNode();
};

template <class T>
node<T>::node()
{
	this->nextNode = nullptr;
}
template <class T>
void node<T>::setNext(node<T>* nextNode)
{
	this->nextNode = nextNode;
}
template <class T>
void node<T>::setInfo(T data)
{
	this->data = data;
}
template <class T>
node<T>* node<T>::getNextNode()
{
	return nextNode;
}
template <class T>
node<T>* node<T>::getPreviousNode()
{
	return previousNode;
}
template<class T>
T node<T>::getData()
{
	return data;
}
template <class T>
void node<T>::printInfo()
{
		std::cout << data << std::endl;
}