
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
	int top;
	T *items;
	int maxStack;

public:
	Stack();
	Stack(int noOfItems);
	~Stack();
	bool push(T item);
	T pop();
	bool isEmpty();
	bool isFull();
};
template <class T>
Stack<T>::Stack()
{
	maxStack = 100;
	top = -1;
	items = new T[100];
}
template <class T>
Stack<T>::Stack(int noOfItems)
{
	maxStack = noOfItems;
	top = -1;
	items = new T[maxStack];
}
template <class T>
Stack<T>::~Stack()
{
	delete[] items;
}
template <class T>
bool Stack<T>::isEmpty()
{
	return (top == -1);
}
template <class T>
bool Stack<T>::isFull()
{
	return (top == maxStack - 1);
}
template <class T>
bool Stack<T>::push(T item)
{
	if (isFull())
	{
		return false;
	}
	items[++top] = item;
	return true;
}
template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		exit(1);
	}
	return items[top--];
}
int main()
{
	Stack<int> obj(50);
	cout << "Zain Ahmad 01-131192-037" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (obj.push(i))
		{
			cout << "Item pushed : " << i << endl;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "Item poped : " << obj.pop() << endl;
	}
	return 0;
}
