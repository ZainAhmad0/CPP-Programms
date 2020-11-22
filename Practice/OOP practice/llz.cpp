#include <iostream>
#include <string>
using namespace std;

struct NodeInfo
{
    NodeInfo *next;
    string name;
    string employeeId;
};

class Node
{

    NodeInfo *head, *current;

public:
    Node()
    {
        head = current = NULL;
    }
    void addNode(string, string);
    void searchById(string);
    void searchByName(string);
    void deleteNodeById(string);
    void deleteNodeByName(string);
    void showAllNodes();
};
void Node :: showAllNodes()
{
    NodeInfo *temp;
    temp = head;
    while (temp!= NULL)
    {
        fflush(stdin);
        cout << endl;
        cout << "ID : " << temp->employeeId << endl;
        cout << "Name : " << temp->name << endl;
        temp = temp->next;
    }
}
void Node ::addNode(string nameOfEmp, string idOfEmp)
{
    fflush(stdin);
    NodeInfo *newNode = new NodeInfo;
    if (head == NULL)
    {
        newNode->employeeId = idOfEmp;
        newNode->name = nameOfEmp;
        newNode->next = NULL;
        head = newNode;
        current = head;
    }
    else
    {
        
        newNode->employeeId = idOfEmp;
        newNode->name = nameOfEmp;
        current->next = newNode;
        current = newNode;        
        current->next = NULL;
    }
}
void Node ::searchById(string idOfEmp)
{
    NodeInfo *temp=new NodeInfo;
    temp = head;
    while (temp != NULL)
    {
        if (temp->employeeId == idOfEmp)
        {
            cout << "Id Found Successfully" << endl;
            cout << "ID : " << temp->employeeId << endl;
            cout << "Name : " << temp->name << endl;
            return;
        }
        temp= temp->next;
    }
    cout << "Id Does Not Found in the system" << endl;
    return ;
}
void Node :: searchByName(string nameOfEmp)
{
    NodeInfo *temp;
    temp = head;
    while (temp != NULL)
    {
        cout<<temp->name<<endl;
        if (temp->name == nameOfEmp)
        {
            cout << "Name Found Successfully" << endl;
            cout << "ID : " << temp->employeeId << endl;
            cout << "Name : " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Name Does Not exists in the system" << endl;
    return;
}
void Node ::deleteNodeById(string idOfEmp)
{
    NodeInfo *temp;
    temp = head;
    while (temp != NULL)
    {
        if ((temp->next->employeeId == idOfEmp))
        {
            NodeInfo *temp2 = temp;
            cout << "ID : " << temp->next->employeeId << endl;
            cout << "Name : " << temp->next->name << endl;
            temp = temp->next;
            temp2->next=temp->next;
            delete temp;
            cout << "Id With name Succesfully Deleted" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "ID Does Not exists in the system" << endl;
    return;
}
void Node ::deleteNodeByName(string nameOfEmp)
{
    NodeInfo *temp;
    temp = head;
    while (temp != NULL)
    {
        if ((temp->next->name == nameOfEmp))
        {
            NodeInfo *temp2 = temp;
            cout << "ID : " << temp->next->employeeId << endl;
            cout << "Name : " << temp->next->name << endl;
            temp = temp->next;
            temp2->next=temp->next;
            delete temp;
            cout << "Name With id Succesfully Deleted" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Name Does Not exists in the system" << endl;
    return;
}

int main()
{
    int choice;
    Node obj;
    cout << "1: Add Employee" << endl;
    cout << "2: Search Employee" << endl;
    cout << "3: Delete Employee" << endl;
    cout << "4: Show All nodes" << endl;
    cout<<"Enter You Choice : ";
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
        {
            string name, id;
            name = id = "";
            fflush(stdin);
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            fflush(stdin);
            cout << "Enter Id : ";
            getline(cin, id);
            obj.addNode(name, id);
            cout<<"Employee Enrolled Successfully"<<endl;
        }
        if (choice == 2)
        {
            char a;
            cout << "        x: Search by name" << endl;
            cout << "        y: Search by id" << endl;
            cin >> a;
            if (a == 'x')
            {
                string name;
                name = "";
                fflush(stdin);
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                obj.searchByName(name);
            }
            else if (a == 'y')
            {
                string id;
                id = "";
                cout << "Enter id: ";
                fflush(stdin);
                cin.ignore();
                getline(cin, id);
                obj.searchById(id);
            }
        }
        if(choice==3)
        {
            char a;
            cout << "        x: Delete by name" << endl;
            cout << "        y: Delete by id" << endl;
            cin >> a;
            if (a == 'x')
            {
                string name;
                name = "";
                fflush(stdin);
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                obj.deleteNodeByName(name);
            }
            else if (a == 'y')
            {
                string id;
                id = "";
                cout << "Enter id: ";
                fflush(stdin);
                cin.ignore();
                getline(cin, id);
                obj.deleteNodeById(id);
            }

        }
        if(choice==4)
        {
            obj.showAllNodes();
        }
        cout<<"Enter You Choice : ";
        cin >> choice;
    }
    return 0;
}