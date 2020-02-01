#include<iostream>

using namespace std;

class calculator_addition_subtraction
{
private:
int num1,num2;
   
public:
 int num_5;
 friend class Data_taker;  // this is the declation to friend class it means that all the member function of the friend class are now friends and can be accessed from the friends class


    calculator_addition_subtraction()
    {
num1=num2=0;   
num_5=0;
    }
    int addition(int n1, int n2)
    {
        num1=n1;
        num2=n2;
        return n1+n2;
        
    }
    int subtraction(int n1, int n2)
    {
        num1=n1;
        num2=n2;
        return n1-n2;
        
    }
 

    ~calculator_addition_subtraction()
    {
cout<<"Destructor Executed Perfectly : class calculator_addition_subtraction"<<endl;
    }
       friend int menu_displayer();
};

int menu_displayer()
{
    calculator_addition_subtraction a;
    
    cout<<"1: Additon"<<endl;
    cout<<"2: Subtration"<<endl;
    cout<<"3: Multiplication"<<endl;
    cout<<"4: Divison"<<endl;
    cin>>a.num_5;
    return a.num_5;

}


class multiplication_division
{
private:
   int num3,num4;
public:
 friend class Data_taker; 
    multiplication_division()
    {
        num3=num4=0;
    }

    int multiplication(int n1,int n2)
    {
        num3=n1;
        num4=n2;
        return num3*num4;
    }
 int division(int n1,int n2)
    {
        num3=n1;
        num4=n2;
        return num3/num4;
    }

    ~multiplication_division()
    {
cout<<"Destructor Executed Perfectly : class multiplication_division"<<endl;
    }
};


class Data_taker
{
    private:
    int a;
    int n1,n2;
public:
void forward_to_appropriate_class()
{
    calculator_addition_subtraction a1;
    multiplication_division zain;
    cout<<"Enter 1st Numbers "<<endl;
    cin>>n1;

    cout<<"Enter 2nd Numbers "<<endl;
    cin>>n2;
    
    a=menu_displayer();
    switch(a)
    {

        case 1:
        cout<<"Addition is: "<< a1.addition(n1,n2)<<endl;
        break;
        case 2:
        cout<<"Subtraction is ("<<n1<<"-"<<n2<<"): " <<a1.subtraction(n1,n2)<<endl;
        break;
        case 3:
        cout<<"Multiplication is: "<<zain.multiplication(n1,n2)<<endl;
        break;
        case 4:
        cout<<"Divison is ("<<n1<<"/"<<n2<<"): "<<zain.division(n1,n2)<<endl;
        break;
        default:
        cout<<"Sorry, Invalid option ..."<<endl;   
    }
}



};
int main()
{
    Data_taker a;
    a.forward_to_appropriate_class();
    return 0;
}



