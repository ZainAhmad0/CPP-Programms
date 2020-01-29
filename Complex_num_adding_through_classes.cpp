#include <iostream>
#include <string>
#include <math.h>


using namespace std;

class CN
{
	private:
	int num1;
	int num2;

	public:
		CN()
	{
		num1=0;
		num2=0;
	}
	CN(int a, int b)
	{
num1=a;
num2=b;
	}
	int rp()
	{
		return num1;
	}
int ip()
	{
		return num2;
	}
	void disp()
	{
		cout<<"The num you have passed is "<<num1<<" + "<<num2<<"i"<<endl;
	}

};

CN adder(CN *b1,CN *b2)
{
	CN result((b1->rp()+b2->rp()),(b1->ip()+b2->ip()));
	return  result;
}

int main()
{
	CN a1(9,5), a2(4,12);
	CN retur;
	retur=adder(&a1,&a2);
	a1.disp();
	a2.disp();
	cout<<"After adding ..."<<endl;
	retur.disp();






}