#include<iostream>

using namespace std;

struct Niu
{
    int a;
    int b;
}obj;
int main()
{
    obj.a=10;
    obj.b=20;
    Niu obj1;
    obj1=obj;
    cout<<obj1.a<<"    "<<obj1.b<<endl;
    cout<<obj.a<<"    "<<obj.b<<endl;
    obj1.a=11; obj1.b=30;
    cout<<obj1.a<<"    "<<obj1.b<<endl;
    cout<<obj.a<<"    "<<obj.b<<endl;
    return 0;
}