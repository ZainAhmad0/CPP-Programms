
#include <iostream>
using namespace std;

template <class T>
struct StackNode
{
    T item;
    StackNode *next;
};

template <class T>
class Stack
{
private:
    StackNode<T> *top;

public:
    Stack();
    ~Stack();
    bool push(T item);
    T pop();
    bool isEmpty();
};
template <class T>
Stack<T>::Stack()
{
    top = NULL;
}
template <class T>
Stack<T>::~Stack()
{
    delete top;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (top == NULL);
}

template <class T>
bool Stack<T>::push(T item)
{
    StackNode<T> *newNode = new StackNode<T>;
    newNode->item = item;
    newNode->next = top;
    top = newNode;
    return true;
}
template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        exit(1); // underflow
    }
    StackNode<T> *temp = new StackNode<T>;
    temp=top;
    top=top->next;
    T item = temp->item;
    delete temp;
    return item;    
}

int main()
{
    Stack<int> obj;
    cout << "Zain Ahmad 01-131192-037" << endl;
    for (int i = 0; i < 15; i++)
    {
        if (obj.push(i))
        {
            cout << "Item pushed : " << i << endl;
        }
    }
    for (int i = 0; i < 15; i++)
    {
        cout << "Item poped : " << obj.pop() << endl;
    }
    return 0;
}
