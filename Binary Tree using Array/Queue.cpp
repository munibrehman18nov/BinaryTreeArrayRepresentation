#include "Queue.h"
#include"NotAllowed.h"

template<typename T> Queue<T>::Queue()
{
	rear = front = noOfElements = 0;
	capacity = 1;
	data = new T[capacity];
}
template<typename T> Queue<T>::~Queue()
{
	if (!data)
		return;
	delete[] data;
	data = 0;
}
template<typename T> bool Queue<T>::isEmpty()
{
	return noOfElements == 0;
}
template<typename T> bool Queue<T>::isFull()
{
	return noOfElements == capacity;
}
template<typename T> int Queue<T>::getCapacity()
{
	return capacity;
}
template<typename T> int Queue<T>::getNoOfElements()
{
	return noOfElements;
}
template<typename T> void Queue<T>::enQueue(T val)
{
	if (isFull())
		reSize(capacity * 2);
	data[rear] = val;
	rear = (rear + 1) % capacity;
	noOfElements++;
}
template<typename T> T Queue<T>::deQueue()
{
	try
	{
		if (isEmpty())
			throw NotAllowed("Empty Queue"); // should throw exception
		T val = data[front];
		front = (front + 1) % capacity;
		noOfElements--;
		if (noOfElements > 0 && noOfElements == capacity / 4)
			reSize(capacity / 2);
		return val;
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template<typename T> T Queue<T>::getElementAtFront()
{
	try
	{
		if (isEmpty())
			throw NotAllowed("Empty Queue"); // should throw exception
		return data[front];
	}
	catch (NotAllowed&n)
	{
		n.printMsg();
	}
}
template<typename T> void Queue<T>::reSize(int newSize)
{
	T * temp = new T[newSize];
	for (int j = 0, i = front; j<noOfElements; j++)
	{
		temp[j] = data[i];
		i = (i + 1) % capacity;
	}
	this->~Queue();
	data = temp;
	capacity = newSize;
	rear = noOfElements;
	front = 0;
}



template Queue<int>;