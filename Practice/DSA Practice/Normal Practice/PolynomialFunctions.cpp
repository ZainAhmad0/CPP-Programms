#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <math.h>

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

int toDigit(char a)
{
    return (a - '0');
}

class Data
{
private:
    float value;
    int degree;
    char sign;

public:
    Data();
    void setValue(float);
    void setDegree(int);
    void setSign(char);
    char getSign();
    float getValue();
    int getDegree();
};

Data::Data()
{
    value = 0;
    degree = 0;
}

void Data ::setSign(char sign1)
{
    sign = sign1;
}
char Data ::getSign()
{
    return sign;
}

void Data ::setValue(float value1)
{
    value = value1;
}
void Data ::setDegree(int degree1)
{
    degree = degree1;
}
float Data ::getValue()
{
    return value;
}
int Data ::getDegree()
{
    return degree;
}

class PolynomialFunctions
{
    DoublyLinkedList<Data> polynomialOne;
    DoublyLinkedList<Data> polynomialTwo;
    ;
    string poly1, poly2;

public:
    void loadPolynomials(string fileName1, string fileName2);
    void addPolynomial();
    void multiplyPolynomial();
    void evaluatePolynomial(float valueOfVariable);
};

void PolynomialFunctions ::loadPolynomials(string fileName1, string fileName2 = "")
{
    Data obj;
    ifstream objFile1(fileName1);
    ifstream objFile2(fileName2);
    string temp, temp2;
    getline(objFile1, poly1);
    getline(objFile2, poly2);
    const int minus = -1;

    for (int i = 0; i < poly1.length(); i++)
    {
        temp2 = "";
        if (poly1[i] == '(')
        {
            i++;
            obj.setSign(poly1[i]);
            i++;
            while (poly1[i] != 'x')
            {
                temp2 += poly1[i];
                i++;
            }
            if (obj.getSign() == '-')
                obj.setValue((minus) * (stof(temp2)));
            else
                obj.setValue(stof(temp2));
            i = i + 2;
            obj.setDegree(toDigit(poly1[i]));
            polynomialOne.insert(obj);
            continue;
        }
    }
    temp = "";
    for (int i = 0; i < poly2.length(); i++)
    {
        temp2 = "";
        if (poly2[i] == '(')
        {
            i++;
            obj.setSign(poly2[i]);
            i++;
            while (poly2[i] != 'x')
            {
                temp2 += poly2[i];
                i++;
            }
            if (obj.getSign() == '-')
                obj.setValue((minus) * (stof(temp2)));
            else
                obj.setValue(stof(temp2));
            i = i + 2;
            obj.setDegree(toDigit(poly2[i]));
            polynomialTwo.insert(obj);
            continue;
        }
    }
}

void PolynomialFunctions ::addPolynomial()
{
    const int minus = -1;
    Data temp, temp1, temp2;
    cout << "Polynomial 1 :" << poly1 << endl;
    cout << "Polynomial 2 :" << poly2 << endl
         << endl;

    for (int i = 0; i < polynomialOne.getLengthOfList(); i++)
    {
        temp = polynomialOne.getItemByIndex(i);
        temp1 = polynomialTwo.getItemByIndex(i);
        cout << "(  " << (temp.getValue()) + (temp1.getValue()) << " x ^ " << (temp.getDegree()) << "  ) + ";
    }
    cout << endl;
}

void PolynomialFunctions ::multiplyPolynomial()
{
    Data temp, temp1, temp2;
    cout << "Polynomial 1 :" << poly1 << endl;
    cout << "Polynomial 2 :" << poly2 << endl
         << endl;

    for (int i = 0; i < polynomialOne.getLengthOfList(); i++)
    {
        temp = polynomialOne.getItemByIndex(i);
        for (int j = 0; j < polynomialTwo.getLengthOfList(); j++)
        {
            temp1 = polynomialTwo.getItemByIndex(j);
            cout << "(  " << (temp.getValue()) * (temp1.getValue()) << " x ^ " << (temp.getDegree()) + (temp1.getDegree()) << "  ) + ";
        }
    }
    cout << endl;
}

void PolynomialFunctions ::evaluatePolynomial(float valueOfVariable)
{
    Data tempObj;
    const int minus = -1;
    float evaluatedPolynomial1, evaluatedPolynomial2;
    evaluatedPolynomial1 = evaluatedPolynomial2 = 0;
    DoublyLinkedList<Data> polynomial1;
    DoublyLinkedList<Data> polynomial2;
    polynomial1 = polynomialOne;
    polynomial2 = polynomialTwo;
    while (!polynomial1.emptyList())
    {
        tempObj = polynomial1.getLastItem();
        if (tempObj.getSign() == '-')
        {
            evaluatedPolynomial1 = float(((evaluatedPolynomial1) + ((minus) * (tempObj.getValue()) * (pow(valueOfVariable, tempObj.getDegree())))));
        }
        else
        {
            evaluatedPolynomial1 = float((evaluatedPolynomial1) + ((tempObj.getValue()) * (pow(valueOfVariable, tempObj.getDegree()))));
        }
        polynomial1.removeLastItem();
    }
    while (!polynomial2.emptyList())
    {
        tempObj = polynomial2.getLastItem();
        if (tempObj.getSign() == '-')
        {
            evaluatedPolynomial2 = float((evaluatedPolynomial2) + ((minus) * (tempObj.getValue()) * (pow(valueOfVariable, tempObj.getDegree()))));
        }
        else
        {
            evaluatedPolynomial2 = float((evaluatedPolynomial2) + ((tempObj.getValue()) * (pow(valueOfVariable, tempObj.getDegree()))));
        }
        polynomial2.removeLastItem();
    }
    cout << "For value : " << valueOfVariable << endl
         << poly1 << "  =  " << evaluatedPolynomial1 << endl;
    cout << "For value : " << valueOfVariable << endl
         << poly2 << "  =  " << evaluatedPolynomial2 << endl;
}

int main()
{
    PolynomialFunctions obj;
    int choice;
    string one, two;
    cout << "Zain Ahmad 01-131192-037" << endl
         << endl;

    cout << "Enter first file name : ";
    getline(cin, one);
    cout << "Enter Second file name : ";
    getline(cin, two);
    obj.loadPolynomials(one, two);
    cout << endl
         << "1: Add polynomials" << endl;
    cout << endl
         << "2: Multiply polynomials" << endl;
    cout << endl
         << "3: Evaluate polynomials" << endl;
    cin >> choice;
    if (choice == 1)
    {
        obj.addPolynomial();
    }
    else if (choice == 2)
    {
        obj.multiplyPolynomial();
    }
    else if (choice == 3)
    {
        cout << "Enter Value of x : ";
        int x;
        cin >> x;
        obj.evaluatePolynomial(x);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}