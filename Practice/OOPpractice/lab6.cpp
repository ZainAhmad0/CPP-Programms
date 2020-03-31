/*
#include<iostream>
using namespace std;

class ArithmeticOperations
{
    int num1;

public:
    ArithmeticOperations();
    int  operator + (ArithmeticOperations obj); 
    int  operator - (ArithmeticOperations obj); 
    float  operator / (ArithmeticOperations obj); 
    int  operator * (ArithmeticOperations obj); 
    void setValue(int);
    
};
ArithmeticOperations :: ArithmeticOperations()
{
    num1=0;
}
int ArithmeticOperations :: operator + (ArithmeticOperations obj)
{
    return num1+obj.num1;
}

int  ArithmeticOperations :: operator - (ArithmeticOperations obj)
{
    return num1-obj.num1;
} 
float  ArithmeticOperations :: operator / (ArithmeticOperations obj)
{
    return num1/obj.num1;
}
int  ArithmeticOperations :: operator * (ArithmeticOperations obj)
{
    return num1*obj.num1;
}
void ArithmeticOperations :: setValue(int a)
{
    num1=a;
}


int main()
{
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    ArithmeticOperations c1,c2;
    int a,b,c;
    cout<<"Enter Value of c1 : "<<endl;
    cin>>a;
    c1.setValue(a);
    cout<<"Enter Value of c2 : "<<endl;
    cin>>b;
    c2.setValue(b);
    cout<<"Press 1 : +"<<endl;
    cout<<"Press 2 : -"<<endl;
    cout<<"Press 3 : *"<<endl;
    cout<<"Press 4 : /"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
        { cout<<"Addition is : "<<c1+c2<<endl;     break ; }
        case 2:
        { cout<<"Subtraction is : "<<c1-c2<<endl;    break;}
        case 3:
        { cout<<"Multiplication is : "<<c1*c2<<endl;    break;  }
        case 4:
        {    if(b!=0)
            cout<<"Div is : "<<c1/c2<<endl;         }
        default:
        cout<<"Invalid choice "<<endl;    break;
    }
    return 0;
}
*/

#include<iostream>
#include<string>
using namespace std;

class JoinString
{
    string name;
public:
    JoinString(string);
    void setValues(string str1);
    string operator + (JoinString obj);
    string getName();   
};

JoinString :: JoinString(string str1)
{
    name=str1;
}
void JoinString :: setValues(string str1)
{
    name=str1;
}
string JoinString ::  operator + (JoinString obj)
{
    name.append(obj.name); // this function is used to append strings
    return name;
}
string JoinString :: getName()
{
    return name;
}
int main()
{
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    string firstName = "Bahria ";
    string secondName = "University";
    JoinString obj1(firstName),obj2(secondName);
    string joinedName = obj1+obj2;
    cout<<"After concatenation through operator overloading "<<endl;
    cout<<joinedName<<endl;
}