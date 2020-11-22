
/*
// task 1


#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue
{
private:
    int count;
    int maxQueue;
    int front;
    int rear;
    T *items;

public:
    Queue();
    Queue(int max);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    T remove();
    void insert(T newItem);
};
template <class T>
Queue<T>::Queue()
{
    count = front = rear = 0;
    maxQueue = 100;
    items = new T[maxQueue];
}
template <class T>
Queue<T>::Queue(int max)
{
    count = front = rear = 0;
    maxQueue = max;
    items = new T[maxQueue];
}
template <class T>
Queue<T>::~Queue()
{
    delete[] items;
}
template <class T>
bool Queue<T>::isEmpty() const
{
    return (count == 0);
}
template <class T>
bool Queue<T>::isFull() const
{
    return (count == maxQueue);
}
template <class T>
T Queue<T>::remove()
{
    if (isEmpty())
    {
        exit(1);
        // underflow
    }
    T temp = items[front];
    front = (front + 1) % maxQueue;
    count--;
    return temp;
}

template <class T>
void Queue<T>::insert(T newItem)
{
    if (isFull())
    {
        exit(1);
        // overflow
    }
    items[rear] = newItem;
    rear = (rear + 1) % maxQueue;
    count++;
}

template <class S>
class Stack
{
private:
    int top;
    S *items;
    int maxStack;

public:
    Stack();
    Stack(int noOfItems);
    ~Stack();
    bool push(S item);
    S pop();
    bool isEmpty();
    bool isFull();
};
template <class S>
Stack<S>::Stack()
{
    maxStack = 100;
    top = -1;
    items = new S[100];
}
template <class S>
Stack<S>::Stack(int noOfItems)
{
    maxStack = noOfItems;
    top = -1;
    items = new S[maxStack];
}
template <class S>
Stack<S>::~Stack()
{
    delete[] items;
}
template <class S>
bool Stack<S>::isEmpty()
{
    return (top == -1);
}
template <class S>
bool Stack<S>::isFull()
{
    return (top == maxStack - 1);
}
template <class S>
bool Stack<S>::push(S item)
{
    if (isFull())
    {
        return false;
    }
    items[++top] = item;
    return true;
}
template <class S>
S Stack<S>::pop()
{
    if (isEmpty())
    {
        exit(1);
    }
    return items[top--];
}

bool isQueueCanBeSortedIntoAnotherQueueUsingStack(int n, Queue<int> queueObj)
{
    Stack<int> st;
    int expected = 1;
    int a;

    // while given Queue is not empty.
    while (!queueObj.isEmpty())
    {
        a = queueObj.remove();
        if (a == expected)
            expected++;

        else
        {
            if (st.isEmpty())
            {
                st.push(a);
            }
            else if (!st.isEmpty() && st.pop() < a)
            {
                return false;
            }

            // else push into the stack.
            else
                st.push(a);
        }

        // while expected element are coming from
        // stack, pop them out.
        while (!st.isEmpty() && st.pop() == expected)
        {
            st.pop();
            expected++;
        }
    }

    // if the final expected element value is equal
    // to initial Queue size and the stack is empty.
    if (expected - 1 == n && st.isEmpty())
        return true;

    return false;
}

int main()
{
    Queue<int> objQueue(5);
    int num[] = {10, 80, 77, 2, 65};
    for (int i = 0; i < 5; i++)
    {
        objQueue.insert(num[i]);
    }
    cout << "queue is : [ ";
    for (int i = 0; i < 5; i++)
    {
        cout << num[i] << ", ";
    }
    cout << " ]" << endl;
    if (isQueueCanBeSortedIntoAnotherQueueUsingStack(5, objQueue))
        cout << "yes" << endl;
    else
    {
        cout << "no" << endl;
    }
    return 0;
    // now the elements are inserted into the queue;
}



// task 2



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
int precedency(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '$')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Stack<char> obj(50);
    Stack<char> obj1(50);
    char temp;
    bool flag = true;
    string convertedExpression = "";
    int precedencyOfOperator1, precedencyOfOperator2, counter, choice;
    precedencyOfOperator1 = precedencyOfOperator2 = counter = 0;
    ifstream read("Expressions.txt");
    string expression;
    getline(read, expression);
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
    if (!obj1.isEmpty() && flag)
    {
        cout << expression << endl;
        cout << "Is is an invalid expression, program is exiting" << endl;
        return 0;
    }
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
            expression[i] == '/' || expression[i] == '$' || expression[i] == '(' ||
            expression[i] == ')')
        {
            if (!obj.isEmpty()) // this condition is applied because pop operation is used inside of this if condition
            {
                if (expression[i] == '(')
                {
                    obj.push(expression[i]);
                }
                else if (expression[i] == ')')
                {
                    temp = obj.pop();
                    while (temp != '(')
                    {
                        convertedExpression = convertedExpression + temp;
                        temp = obj.pop();
                    }
                }
                else
                {
                    temp = obj.pop();
                    precedencyOfOperator1 = precedency(expression[i]);
                    precedencyOfOperator2 = precedency(temp);
                    if (precedencyOfOperator1 > precedencyOfOperator2)
                    {
                        obj.push(temp);
                        obj.push(expression[i]);
                    }
                    else if (precedencyOfOperator1 == precedencyOfOperator2)
                    {
                        convertedExpression = convertedExpression + temp;
                        obj.push(expression[i]);
                        // associativity rule (left to right) is used which states
                        // Pop and print the top of the stack and push the incoming operator 
                    }
                    else
                    // This else will handle all operations regarding lower precedence of operators
                    {
                        while (precedencyOfOperator1 < precedencyOfOperator2)
                        {
                            convertedExpression = convertedExpression + temp;
                            if (!obj.isEmpty())
                            {
                                temp = obj.pop();
                                precedencyOfOperator1 = precedency(expression[i]);
                                precedencyOfOperator2 = precedency(temp);
                            }
                            else
                            {
                                obj.push(expression[i]);
                                break;
                            }
                        }
                        if (precedencyOfOperator1 == precedencyOfOperator2)
                        // e.g if '*' is in the stack and incoming                                    operator is '/' now both have same precedency
                        {
                            convertedExpression = convertedExpression + temp;
                            obj.push(expression[i]);
                            // associativity rule (left to right) is used which states
                            // Pop and print the top of the stack and push the incoming operator
                        }
                        else
                        {
                            obj.push(temp);
                            obj.push(expression[i]);
                        }
                    }
                }
            }
            else
            {
                obj.push(expression[i]);
            }
        }
        else
        {
            convertedExpression = convertedExpression + expression[i];
        }
    }
    // at the end of the expression the operators in the stack are appended at the end of the expression
    while (!obj.isEmpty())
    {
        temp = obj.pop();
        convertedExpression = convertedExpression + temp;
    }
    cout << "Expression before conversion : " << expression << endl;
    cout << "Expression after conversion : " << convertedExpression << endl;
    return 0;
}

// task 3

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

void printDecimalToBinaryInReverseOrder(int number)
{
    int i, j, k;
    i = j = k = 0;
    int binaryNumber[30]; // this is to store binary number
    while (number > 0)
    {
        binaryNumber[i++] = number % 2;
        number /= 2;
    }
    // now the binary number is stored into binaryNumber array  in reverse order from 0 to end index in array
    // now reversing the array binaryNumber to get the binary number in real order;
    int *binaryNumber1 = new int[i];
    for (j = i - 1; j >= 0; j--)
    {
        binaryNumber1[k] = binaryNumber[j];
        k++;
    }
    // now the binaryNumber1 array contains the binary of the given number in real order from 0 to that end index
    // now i am going to reverse the binary number using stack data structure
    Stack<int> obj(i);
    for (int j = 0; j < i; j++)
    {
        obj.push(binaryNumber1[j]);
    }
    // now the binary number is pushed into the stack now printing it into reverse order
    while (!obj.isEmpty())
    {
        cout << obj.pop();
    }
}

int main()
{
    int number;
    cout << "Zain Ahmad 01-131192-037" << endl;
    cout << "Enter deciaml number : ";
    cin >> number;
    cout << "Reverse Order binary of " << number << " is : ";
    printDecimalToBinaryInReverseOrder(number);
    cout << endl;
    return 0;
}


*/