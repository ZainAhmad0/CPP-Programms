#include <iostream>
#include <string>
#include <fstream>
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
    void push(T item);
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
void Stack<T>::push(T item)
{
    if (isFull())
    {
        exit(1);
    }
    items[++top] = item;
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
    Stack<char> obj(50);
    Stack<char> obj1(50);
    bool flag = true;
    string expression;
    expression = "[a+c)]";
    // validating the expression now
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            obj1.push(expression[i]);
            continue;
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            char temp = obj1.pop();
            if (expression[i] == ')')
            {
                if (temp != '(')
                {
                    flag = false;
                    break;
                }
            }
            else if (expression[i] == '}')
            {
                if (temp != '{')
                {
                    flag = false;
                    break;
                }
            }
            else if (expression[i] == ']')
            {
                if (temp != '[')
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (!(obj1.isEmpty() && flag))
    {
        cout << expression << endl;
        cout << "Is is an invalid expression" << endl;
    }
    else
    {
        cout << expression << endl;
        cout << "Is is valid expression" << endl;
    }

    return 0;
}