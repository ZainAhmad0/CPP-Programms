#include<iostream>

using namespace std;
class add
{
    private :
    int a,b;
    public :

    add()
    {
        a=0; b=0;
    }
    int addd(int v, int e)
    {
a=v; b=e;
cout<<"Result after adding is ... "<<a+b<<endl;
    }
};

int main()
{
add a;
int aa,bb;
cout<<"Enter 1st Digit:  "; 
cin>>aa;
cout<<"Enter 2nd Digit:  "; 
cin>>bb;
cout<<endl;
a.addd(aa,bb);
return 0;
}