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
	int getData();
	void setNext(T);
	void setInfo(T);
	void printInfo();
	node<T>* getNode();

	
};

template <class T>
node<T>::node()
{
	this->nextNode = nullptr;
}
template <class T>
void node<T>::setNext(T data)
{
	nextNode = new node(data);
}
template <class T>
void node<T>::setInfo(T data)
{
	this->data = data;
}
template <class T>
node<T>* node<T>::getNode()
{
	return nextNode;
}
template<class T>
int node<T>::getData()
{
	return data;
}
template <class T>
void node<T>::printInfo()
{
		std::cout << data << std::endl;
}