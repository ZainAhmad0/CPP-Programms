/*
// quesiton # 01

#include <iostream>
#include <string>
using namespace std;

struct Info 
{
    // because there are red,blue,green and yellow goat colors
    bool r1, r2, r3, r4,
        b1, b2, b3, b4,
        g1, g2, g3, g4,
        y1, y2, y3, y4;
};

struct LudoNode
{
    Info obj;
    bool stop;  
    LudoNode *next, *backward,
        *bottomRight, *bottomMid, *bottomLeft,
        *topRight, *topMid, *topLeft;
    LudoNode()
    {
        bottomLeft = NULL;
        bottomMid = NULL;
        bottomRight = NULL;
        topLeft = NULL;
        topRight = NULL;
        topMid = NULL;
        next = NULL;
        backward = NULL;
    }
};

class Ludo
{
private:
    LudoNode *head, *tail;
    // head pointer is for starting and tail pointer points to the end node

public:
    Ludo();
    void createLudoBoard(int count);
};

Ludo::Ludo()  
{
    head->obj.r1 = false;
    head->obj.r2 = false;
    head->obj.r3 = false;
    head->obj.r4 = false;
    head->obj.b1 = false;
    head->obj.b2 = false;
    head->obj.b3 = false;
    head->obj.b4 = false;
    head->obj.g1 = false;
    head->obj.g2 = false;
    head->obj.g3 = false;
    head->obj.g4 = false;
    head->obj.y1 = false;
    head->obj.y2 = false;
    head->obj.y3 = false;
    head->obj.y4 = false;
    head->stop = false;
}

void Ludo ::createLudoBoard(int count)
{
    head->stop = true; // head node starts with stop
    for (int i = 0; i < count; i++)
    {
        LudoNode *newNode = new LudoNode;
        if (head == NULL && tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->backward = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    int i = 0;
    // beacuse there are total 49 spaces in ludo excluding the home spaces 
    // after traversing 7 boxes in ludo there is stop box
    // and after traversing 7 box again after traversing 4 box more the next is stop box 
    // so stop box comes in multiple of 7 and 11(7+4)  
    for (LudoNode *temp = head; temp != NULL; temp = temp->next)
    {
        // ex at traversing from 0th index the 8th boa would be stop 
        // ex after traversing 8th position (8+5)th box would be stop 
        // so in this way I have specified the conditions
        if (i == 8 || i == 21 || i == 34 || i == 47)
        {
            temp->stop = true;
        }
        else if (i == 13 || i == 26 || i == 39)
        {
            temp->stop = true;
        }
        i++;
    }
    tail->next = head; // beacuse ludo boards are form of circular linked list
}

int main()
{
    Ludo objLudo;
    objLudo.createLudoBoard(49); // without home boxes
    return 0;
}

*/

/*
// quesiton # 02

#include<iostream>
using namespace std;

LudoNode* moveGoat(LudoNode *p, string goatColor, int diceValue)
{
    for(int i=0; i<diceValue; i++)
    {
        p=p->next;
    }
    // now our goat is moved at the required dice value location now it will check for the goal to kill
    if(p->goatColor != goatColor)
    {
        killGoat();
    }
    return p; // return the current location at which out goat is present now;
}

*/
