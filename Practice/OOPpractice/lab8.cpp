#include<iostream>
using namespace std;

class Square
{
    int num;
public:
Square(int a)
{
    num=a;        
}
int calculateSquare()
{
    int a=num*num;
    return a;
}
};
class Cube : public Square
{
    int num1;
public:
Cube(int num,int num2) : Square(num)
{
    num1=num2;
}
int calculateCube()
{
    int a=num1*num1*num1;
    return a;
}
};

int main()
{
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    int num1,num2;
    cout<<"Please enter a number for square : ";
    cin>>num1;
    cout<<"Please enter a number for Cube : ";
    cin>>num1;
    Cube obj(num1,num2);
    Square obj1;
    cout<<"Squre of number is : "<<obj1.calculateSquare()<<endl;
    cout<<"Cube of the numbre is: "<<obj.calculateCube()<<endl;
    return 0;
}