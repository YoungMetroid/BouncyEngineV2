#pragma once
template<class T>
class node
{
private:
	T *data;
	
public:
	template<class T> void setNext(T data);
};


