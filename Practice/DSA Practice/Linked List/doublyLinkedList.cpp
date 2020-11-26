#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node<T> *next, *previous;

public:
    Node();
    void setData(T);
    T getData();
    Node *getNext();
    void setNext(Node *);
    Node *getPrevious();
    void setPrevious(Node *);
};

template <class T>
Node<T>::Node()
{
    previous = NULL;
    next = NULL;
}

template <class T>
Node<T> *Node<T>::getPrevious()
{
    return previous;
}

template <class T>
void Node<T>::setPrevious(Node *previous1)
{
    previous = previous1;
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
class DoublyLinkedList
{
private:
    Node<S> *head;

public:
    DoublyLinkedList();
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
    void displayList();
    S getItemByIndex(int index); // get item by index
    int getLengthOfList();       // get length of list
};

template <class S>
int DoublyLinkedList<S>::getLengthOfList()
{
    Node<S> *temp = head;
    int i = 1;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (temp->getNext() != NULL)
        {
            i++;
            temp = temp->getNext();
        }
        return i;
    }
}

template <class S>
S DoublyLinkedList<S>::getItemByIndex(int index)
{
    Node<S> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->getNext();
    }
    return temp->getData();
}

template <class S>
DoublyLinkedList<S>::DoublyLinkedList()
{
    head = new Node<S>();
    head = NULL;
}

template <class S>
void DoublyLinkedList<S>::displayList()
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
bool DoublyLinkedList<S>::emptyList()
{
    return (head == NULL);
}

template <class S>
void DoublyLinkedList<S>::insertAtStart(S data)
{
    Node<S> *obj = new Node<S>();
    obj->setData(data);
    obj->setNext(head);
    obj->setPrevious(NULL);
    if (head == NULL)
        head = obj;
    else
    {
        head->setPrevious(obj);
        head = obj;
    }
}

template <class S>
S DoublyLinkedList<S>::deleteFromStart()
{
    if (!emptyList())
    {
        Node<S> *temp = head;
        head = head->getNext();
        head->setPrevious(NULL);
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
void DoublyLinkedList<S>::removeFront() // delete starting item
{
    if (emptyList())
    {
        exit(1); // trying to remove head from empty list
    }
    Node<S> *temp = head;
    head = head->getNext();
    head->setPrevious(NULL);
    delete temp;
}

template <class S>
void DoublyLinkedList<S>::insert(S data) // add to back
{
    Node<S> *temp = head;
    if (head == NULL) // if it is inserting at starting position at first time
    {
        Node<S> *newNode = new Node<S>;
        newNode->setPrevious(NULL);
        newNode->setData(data);
        newNode->setNext(NULL);
        head = newNode;
        return;
    }
    else // not at start
    {
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
    }
    Node<S> *newNode = new Node<S>();
    temp->setNext(newNode);
    newNode->setPrevious(temp);
    newNode->setData(data);
    newNode->setNext(NULL);
}

template <class S>
S DoublyLinkedList<S>::getLastItem() // return last item
{
    Node<S> *temp = head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    return temp->getData();
}

template <class S>
void DoublyLinkedList<S>::removeLastItem() // remove last element in the list
{
    Node<S> *deletingNode = head;
    while (deletingNode->getNext() != NULL)
    {
        deletingNode = deletingNode->getNext();
    }
    Node<S> *temp = deletingNode->getPrevious();
    if (temp == NULL)
    {
        head = NULL;
        delete deletingNode;
        return;
    }
    temp->setNext(NULL);
    delete deletingNode;
}

template <class S>
bool DoublyLinkedList<S>::findInList(S data) // is particular item in the list ?
{
    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == data || temp->getNext()->getData() == data) // extra condition is implemented cuz at last node it wont chek the data without it.
        {
            return true;
        }
    }
    return false;
}

template <class S>
bool DoublyLinkedList<S>::deleteItem(S data) // delete particulat data from the list
{
    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == data)
        {
            if (temp == head) // if it is at starting node
            {
                head = temp->getNext();
                head->setPrevious(NULL);
                delete temp;
                return true;
            }
            Node<S> *temp1 = temp->getPrevious();
            Node<S> *temp2 = temp->getNext();
            temp1->setNext(temp2);
            if (temp2 != NULL) // if it is at last node
            {
                temp2->setPrevious(temp1);
            }
            delete temp;
            return true;
        }
    }
    return false;
}

template <class S>
bool DoublyLinkedList<S>::insertBefore(S newData, S dataToInsertBefore) // add item before particular data
{

    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == dataToInsertBefore || temp->getNext()->getData() == dataToInsertBefore) // data in somewhere middle or last
        {
            if (temp == head) // at start
            {
                Node<S> *temp1 = new Node<S>();
                temp1->setNext(temp);
                temp1->setData(newData);
                temp1->setPrevious(NULL);
                temp->setPrevious(temp1);
                head = temp1;
                return true;
            }
            if (temp->getNext()->getData() == dataToInsertBefore) // insertion before last node
            {
                temp = temp->getNext();
            }
            Node<S> *temp1 = new Node<S>();
            Node<S> *newNode = new Node<S>();
            temp1 = temp->getPrevious();
            newNode->setNext(temp);
            newNode->setData(newData);
            temp1->setNext(newNode);
            newNode->setPrevious(temp1);
            temp->setPrevious(newNode);
            return true;
        }
    }
    return false;
}

template <class S>
bool DoublyLinkedList<S>::insertAfter(S newData, S dataToInsertAfter) // add item after particular data
{
    for (Node<S> *temp = head; temp->getNext() != NULL; temp = temp->getNext())
    {
        if (temp->getData() == dataToInsertAfter || temp->getNext()->getData() == dataToInsertAfter) // at somewhere middle or last
        {
            Node<S> *newNode = new Node<S>();
            newNode->setData(newData);
            newNode->setNext(temp->getNext());
            if (temp->getNext() != NULL)
            {
                temp->getNext()->setPrevious(newNode);
            }
            newNode->setPrevious(temp);
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
    DoublyLinkedList<int> obj;
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
            obj.displayList();
            cout << "Last item is : " << obj.getLastItem() << endl;
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
            int newItem, oldItem;
            cout << "Enter item to insert after : ";
            cin >> oldItem;
            cout << "Enter new item : ";
            cin >> newItem;
            if (obj.insertAfter(newItem, oldItem))
                cout << "Item inserted" << endl;
            else
            {
                cout << "Old item not found, so data not inserted" << endl;
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
                cout << "Item not inserted, old item not found" << endl;
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