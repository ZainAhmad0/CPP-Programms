#include<iostream>
#include<string>
using namespace std;
class A
{
protected:
const int a=10;
const int a1=20;
public:
void printInfo1(){
    cout<<"A = "<<a<<endl;
}
void printInfo2(){
    cout<<"A1 = "<<a1<<endl;    
}

};
class B : public A
{
protected:
const int b=6;
const int b1=4;
public:
void printInfo1(){
    cout<<"A = "<<a<<endl;
    cout<<"A1 = "<<a1<<endl; 
}
void printInfo2(){
    cout<<"B = "<<b<<endl;
    cout<<"b1 = "<<b1<<endl;
    
}

};
void print (A obj)
{
obj.printInfo1(); 
obj.printInfo2(); 
}
int main()
{
    cout<<"Zain Ahmad (01-131192-037)"<<endl;
    A a;
    B b;
    a.printInfo1();
    b.printInfo1();
    a.printInfo2();
    b.printInfo2();
    print(a);
    return 0;
}