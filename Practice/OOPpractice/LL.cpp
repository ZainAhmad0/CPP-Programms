#include<iostream>
#include<string>

using namespace std;

struct Node
{
    int rollNo;
    string name;
    Node *next;
};

int main()
{
    Node *head,*tail,*nexdNode;
    int choice=0;
    choice=1;
    int count = 0;
    string name= "zain";
    int rollNo=20;
    head=nexdNode=tail=0;
    if(choice==1)
    {
        Node *newNode= new Node;
        if(count==0)
        {
            head=tail=newNode=newNode->next;
        }
        else
        {
            tail=0;
            newNode->next=0
            newNode->name=name;
            newNode->rollNo=rollNo;            
        }
        
        

      

                    
        

    }
}