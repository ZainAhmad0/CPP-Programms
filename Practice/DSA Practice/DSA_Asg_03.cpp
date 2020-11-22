//DSA Assignment No 3
// Priority Queue implementation using Queue class header file
/*
To:
Sir Adeel
By:
1 - Zain Ahmad (01-131192-037)
2 - Mirza Haris (01-131192-019)
3 - Ahmed Shahzad Qayani (01-131192-003)
Dated: 20/10/2020
*/


#include "myQueue.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Data
{
private:
    char priority;
    int number;

public:
    Data();
    void setPriority(char priority);
    char getPriority();
    void setNumber(int number1);
    int getNumber();
};

Data ::Data()
{
}

void Data ::setPriority(char priority1)
{
    priority = priority1;
}

char Data ::getPriority()
{
    return priority;
}

void Data ::setNumber(int number1)
{
    number = number1;
}

int Data ::getNumber()
{
    return number;
}

int toDigit(char a)
{
    return (a - '0');
}

int calculateNumber(int digit1, int digit2)
{
    return ((digit1 * 10) + digit2);
    /*
        for example number = 23 then digit1 = 2 and digit2 = 3
        so (2*10)+3=23
    */
}

int main()
{

    Queue<int> objQueue(25); // because there are 25 elements in the text file
    Data objData[25];        // because there are 25 data elements in the text file
    Data objTemp;
    int i, number;
    number = i = 0;
    string dataElement = "";
    ifstream read("elements.txt");
    while (getline(read, dataElement))
    {
        // exmaple a23 then
        // dataElement[0] = 'a', dataElement[1] = '2' and dataElement[2] = '3'
        number = calculateNumber(toDigit(dataElement[1]), toDigit(dataElement[2]));
        objData[i].setPriority(dataElement[0]);
        objData[i].setNumber(number);
        i++;
    }

    // now i am sorting the Data elements stored in objData[] array on the basis of their priority
    for (int i = 0; i < 25; i++)
    {
        for (int j = i; j < 25; j++)
        {
            if (objData[i].getPriority() > objData[j].getPriority())
            {
                objTemp = objData[i];
                objData[i] = objData[j];
                objData[j] = objTemp;
            }
        }
    }

    // now the priority wised Data elements are sorted and now inserted into the queue

    for (int i = 0; i < 25; i++)
    {
        objQueue.insert(objData[i].getNumber());
    }


    // now the elements are successfully inserted in to the queue based on the priority
    // now displaying the elements on the basis of their priority

    for (int i = 0; i < 25; i++)
    {
        cout << objQueue.remove() << "   ";
    }
    return 0;
}
