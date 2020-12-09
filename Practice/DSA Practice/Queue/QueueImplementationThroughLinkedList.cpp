#include <iostream>
using namespace std;

template <class T>
struct QueueNode
{
    T item;
    QueueNode *next;
};

template <class T>
class Queue
{
private:
    QueueNode<T> *front;
    QueueNode<T> *rear;

public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    T remove();
    void insert(T newItem);
};
template <class T>
Queue<T>::Queue()
{
    front = rear = NULL;
}

template <class T>
Queue<T>::~Queue()
{
    delete front;
    delete rear;
}

template <class T>
bool Queue<T>::isEmpty() const
{
    return (front == NULL && rear == NULL);
}

template <class T>
T Queue<T>::remove()
{
    if (isEmpty())
    {
        exit(1);
        // underflow
    }
    QueueNode<T> *temp = new QueueNode<T>;
    if (front == rear)
    {
        temp = front;
        front = rear = NULL;
    }
    else
    {

        temp = front;
        front = front->next;
    }
    T item = temp->item;
    delete temp;
    return item;
}

template <class T>
void Queue<T>::insert(T newItem)
{
    QueueNode<T> *newNode = new QueueNode<T>;
    newNode->item = newItem;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}

int main()
{
    Queue<int> obj;
    int num;
    cout << "Zain Ahmad 01-131192-037" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Element inserted : " << i + 10 << endl;
        obj.insert(i + 10);
    }
    cout << "10 elements inserted in queue" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " : " << obj.remove() << endl;
    }
    cout << "10 elements removed from queue" << endl;
    return 0;
}