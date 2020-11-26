#include <iostream>
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
    Queue<int> obj(10);
    int num;
    cout << "Zain Ahmad 01-131192-037" << endl;
    cout << "Insert 10 Elements in queue " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter " << i + 1 << " element : ";
        cin >> num;
        obj.insert(num);
    }
    cout << "10 elements inserted in queue" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " : " << obj.remove() << endl;
    }
    cout << "10 elements removed from queue" << endl;
    return 0;
}