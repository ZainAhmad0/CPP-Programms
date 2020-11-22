#include<iostream>
#include<string>
using namespace std;

class A
{
    public:
    virtual void disp() =0 ;
       // cout<<"A disp"<<endl;
};
class B : public A
{
   public:
    void disp()
   {
       cout<<"B disp"<<endl;
   }
};
int main()
{
    A *obj;
    B *obj2,obj3;
    obj3.disp();
    obj->disp();
    obj=&obj3; // late binding would be done here
    obj->disp();
    return 0;
}
