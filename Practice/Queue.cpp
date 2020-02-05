#include <iostream>
#include <string>
using namespace std;

class queue
{
protected:
    int head, tail;
    int queuee[10];

public:
    queue()
    {
        head = tail = -1;
    }

    int dequeue()
    {
        tail++;
    }

    int enqueue(int var)
    {
        queuee[++head] = var;
    }
};

class queuee2 : public queue
{
public:
    int dequeue()
    {
        if (tail == -1 && head == -1 || head == tail)
        {
            head = tail = -1;
            return 0;
        }

        else
            queue::dequeue();
        return 1;
    }
    int enqueue(int var)
    {
        if (head + 1 > 10)
            return 0;
        else
        {
            queue::enqueue(var);
            return 1;
        }
    }
    void Elements_disp()
    {
        cout<<endl;
        for (int i = tail + 1; i < head + 1; i++)
            cout << queuee[i] <<"     ";
        cout<<endl;
    }
};

int main()
{
    queuee2 obj;
    cout<<endl;
    int choice=1;
    while(choice ==1 || choice == 2 || choice == 3)
    {
        
        
    cout << "1: Enqueue " << endl
         << "2: Dequeue" << endl
         << "3: View Current Elements In Queue " << endl<<endl;
         cout<<"Please Enter an choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int element;
       cout << "Please Insert An Integer Element :  ";
        cin >> element;
        
       if( obj.enqueue(element)==0)
       {
           cout<<"Queue Is Full with elements ... "<<endl;;
           obj.Elements_disp();
       }
            break;
    }
    case 2:
    {
        cout<<endl<<endl;
        cout<<"Befor Deuque, Elements are ..."<<endl;
        obj.Elements_disp();
        if(obj.dequeue()==0)
        {
            cout<<"Queue is Empty..."<<endl<<endl;
            break;
        }
        cout<<"After Deuque, Elements are ..."<<endl;
        obj.Elements_disp();
        cout<<endl<<endl;
        break;
    }
    case 3:
    {
    obj.Elements_disp();
    break;
    }
    default:
    cout<<"Exiting because Invalid Choice entered ... "<<endl;
    }
    }
}