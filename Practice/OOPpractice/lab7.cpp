#include<iostream>
using namespace std;

class Arithmetic
{
protected:
    float num1,num2;
public:
    Arithmetic(float numA,float numB)
    {
        num1=numA;
        num2=numB;
    }
};
class ArithmeticOperations: public Arithmetic
{
public:
    ArithmeticOperations(float a,float b):Arithmetic (a,b)
    {           }
    int getAddition()
    {
        return num1+num2; 
    }
    int getMultiplication()
    {
        return num1*num2;
    }
    int getSubtraction()
    {
        return num1-num2;
    }
    float getDiv()
    {
        if(num2!=0)
        return num1/num2;
        else 
        cout<<"Cannot divide, because num2 = 0"<<endl;
    }

};

int main()
{
    float num1,num2;
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    cout<<"Enter number 1 : ";
    cin>>num1;
    cout<<"Please Enter num 2 : ";
    cin>>num2;
    ArithmeticOperations obj(num1,num2); 
    cout<<"Addition is : "<<obj.getAddition()<<endl;
    cout<<"Subtraction is : "<<obj.getSubtraction()<<endl;
    cout<<"Multiplicaiton is : "<<obj.getMultiplication()<<endl;
    cout<<"Division is : "<<obj.getDiv()<<endl;
    return 0;
}
