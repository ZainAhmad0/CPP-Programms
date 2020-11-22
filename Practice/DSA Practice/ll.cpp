#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node();
    void setData(T);
    T getData();
    Node *getNext();
    void setNext(Node *);
};

template <class T>
Node<T>::Node()
{
    next = NULL;
}

template <class T>
void Node<T>::setData(T data1)
{
    data = data1;
}

template <class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T> *next1)
{
    next = next1;
}

template <class S>
class LinkedList
{
private:
    Node<S> *head;

public:
    LinkedList();
    bool emptyList();
    void insertAtStart(S data);                         // add to start
    S deleteFromStart();                                // return starting item and delete it
    void removeFront();                                 // delete starting item
    void insert(S data);                                // add to back
    S getLastItem();                                    // return last item
    void removeLastItem();                              // remove last element in the list
    bool findInList(S data);                            // is particular item in the list ?
    bool deleteItem(S data);                            // delete particulat data from the list
    bool insertBefore(S newData, S dataToInsertBefore); // add item before particular data
    bool insertAfter(S newData, S dataToInsertAfter);   // add item after particular data
    void displayList();                                 // to display the list
};

template <class S>
LinkedList<S>::LinkedList()
{
    head = NULL;
}

template <class S>
void LinkedList<S>::displayList()
{
    cout << endl;
    for (Node<S> *temp = head; temp != NULL; temp = temp->getNext())
    {
        cout << temp->getData() << "   ";
    }
    cout << endl
         << endl;
}

template <class S>
bool LinkedList<S>::emptyList()
{
    return (head == NULL);
}

template <class S>
void LinkedList<S>::insertAtStart(S data)
{
    Node<S> *obj = new Node<S>();
    obj->setData(data);
    obj->setNext(head);
    head = obj;
}

template <class S>
S LinkedList<S>::deleteFromStart()
{
    if (!emptyList())
    {
        Node<S> *temp = head;
        head = head->getNext();
        S tempData = temp->getData();
        delete temp;
        return tempData;
    }
    else
    {
        exit(0); // the list is empty and the user tried to delete item from empty list -- underflow.
    }
}

template <class S>
void LinkedList<S>::removeFront() // delete starting item
{
    if (emptyList())
    {
        exit(1); // trying to remove head from emptyn list
    }
    Node<S> *temp = head;
    head = head->getNext();
    delete temp;
}

template <class S>
void LinkedList<S>::insert(S data) // add to back
{
    Node<S> *temp = head;
    if (head == NULL) // if it is inserting at starting position at first time
    {
        Node<S> *newNode = new Node<S>;
        newNode->setData(data);
        newNode->setNext(NULL);
        head = newNode;
        return;
    }
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    Node<S> *newNode;
    newNode = new Node<S>();
    temp->setNext(newNode);
    newNode->setData(data);
    newNode->setNext(NULL);
}

template <class S>
S LinkedList<S>::getLastItem() // return last item
{
    Node<S> *temp = head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    return temp->getData();
}

template <class S>
void LinkedList<S>::removeLastItem() // remove last element in the list
{
    Node<S> *temp = head;
    while (temp->getNext()->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    Node<S> *deletingNode = temp->getNext();
    temp->setNext(NULL);
    delete deletingNode;
}

template <class S>
bool LinkedList<S>::findInList(S data) // is particular item in the list ?
{
    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == data)
        {
            return true;
        }
    }
    return false;
}

template <class S>
bool LinkedList<S>::deleteItem(S data) // delete particulat data from the list
{
    Node<S> *temp1;
    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == data)
        {
            temp1->setNext(temp->getNext());
            delete temp;
            return true;
        }
        temp1 = temp;
    }

    return false;
}

template <class S>
bool LinkedList<S>::insertBefore(S newData, S dataToInsertBefore) // add item before particular data
{
    Node<S> *temp1 = new Node<S>();
    for (Node<S> *temp = head; temp != NULL; temp = temp->getNext())
    {
        if (temp->getData() == dataToInsertBefore) // data in somewhere middle
        {
            if (temp == head)
            {
                temp1->setNext(temp);
                temp1->setData(newData);
                head = temp1;
                return true;
            }
            Node<S> *newNode = new Node<S>();
            newNode->setNext(temp);
            newNode->setData(newData);
            temp1->setNext(newNode);
            return true;
        }
        temp1 = temp;
    }
    return false;
}

template <class S>
bool LinkedList<S>::insertAfter(S newData, S dataToInsertAfter) // add item after particular data
{
    for (Node<S> *temp = head; temp != NULL; temp = temp->getNext())
    {
        if (temp->getData() == dataToInsertAfter)
        {
            Node<S> *newNode = new Node<S>();
            newNode->setData(newData);
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "Zain Ahmad 01-131192-037" << endl
         << endl;
    int choice = -1;
    LinkedList<int> obj;
    while (choice != 0)
    {
        cout << "1 : Delete from start " << endl;
        cout << "2 : Delete Item " << endl;
        cout << "3 : Display list " << endl;
        cout << "4 : Find item in list " << endl;
        cout << "5 : Get last item " << endl;
        cout << "6 : Insert item " << endl;
        cout << "7 : Insert after Item " << endl;
        cout << "8 : insert Before Item " << endl;
        cout << "9 : Remove first Item " << endl;
        cout << "10 : Remove last Item " << endl;
        cout << "11 : Insert At start" << endl;
        cout << endl
             << "0 : Exit" << endl;

        cin >> choice;
        if (choice == 1)
        {
            obj.deleteFromStart();
            obj.displayList();
        }
        else if (choice == 2)
        {
            int item;
            cout << "Enter item : ";
            cin >> item;
            obj.deleteItem(item);
            cout << "Item deleted" << endl;
            obj.displayList();
        }
        else if (choice == 3)
        {
            obj.displayList();
        }
        else if (choice == 4)
        {
            int item;
            cout << "Enter item : ";
            cin >> item;
            if (obj.findInList(item))
                cout << "Item found" << endl;
            else
            {
                cout << "item not found" << endl;
            }
            obj.displayList();
        }
        else if (choice == 5)
        {
            cout << "Last item is : " << obj.getLastItem() << endl;
            obj.displayList();
        }
        else if (choice == 6)
        {
            int item;
            cout << "Enter item : ";
            cin >> item;
            obj.insert(item);
            cout << "Item inserted" << endl;
            obj.displayList();
        }
        else if (choice == 7)
        {
            int itemToInsertAfter;
            int newItem;
            cout << "Enter item to insert after : ";
            cin >> itemToInsertAfter;
            cout << "Enter new data : ";
            cin >> newItem;
            if (obj.insertAfter(newItem, itemToInsertAfter))
                cout << "Item inserted" << endl;
            else
            {
                cout << "Item not inserted" << endl;
            }
            obj.displayList();
        }
        else if (choice == 8)
        {
            int itemToInsertBefore;
            int newItem;
            cout << "Enter item to insert Before : ";
            cin >> itemToInsertBefore;
            cout << "Enter new data : ";
            cin >> newItem;
            if (obj.insertBefore(newItem, itemToInsertBefore))
                cout << "Item inserted" << endl;
            else
            {
                cout << "Item not inserted" << endl;
            }
            obj.displayList();
        }
        else if (choice == 9)
        {
            obj.removeFront();
            cout << "Front removed" << endl;
            obj.displayList();
        }
        else if (choice == 10)
        {
            obj.removeLastItem();
            cout << "last item is removed " << endl;
            obj.displayList();
        }
        else if (choice == 11)
        {
            cout << "Enter item : ";
            int item;
            cin >> item;
            obj.insertAtStart(item);
            cout << "Item Inserted" << endl;
            obj.displayList();
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}