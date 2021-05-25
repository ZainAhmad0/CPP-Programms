#include <iostream>
#include <string>
#include <fstream>

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

int main()
{
    Queue<int> objQueue[26]; // because there are 26 alphabets showing priority
    int i, number;
    int asciiRepresentationVar = 90; // 90 in ascii is 'Z' which means that it is the highest priority element.
    char tempChar;
    number = 0;
    string dataElement = "", temp = "";
    ifstream read("elements.txt");
    while (getline(read, dataElement))
    {
        temp = dataElement;
        temp[0] = '0';
        number = stoi(temp);
        objQueue[int(dataElement[0]) - 65].insert(number);
        /*
        suppose A is the priority level at dataElement[0]
        now 65 represents 'A' in ascii, so objQueue(0) would represent A and 
        afterwards 'B' would represent objQueue(1) and 
        as following 'Z' would represent 25
        */
    }

    for (int j = 25; j >= 0; j--) // j=25 because there are 25+1 priroity levels
    {
        temp = asciiRepresentationVar--;
        /* temp would contain the priority level character
         e.g as asciiRepresentationVar is initialized as 90
         so when it would be casted in char temp, it would contain 'Z'                  
         */
        while (!objQueue[j].isEmpty())
        {
            cout << temp << objQueue[j].remove() << ",";
        }
    }
    cout << endl;
    return 0;
}
