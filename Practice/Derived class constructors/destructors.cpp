#include<iostream>
#include <string>

using namespace std;


// Contructor is Always called from Top to botton -i-e from parent class to child class

/* 
Contructor is Always called from Top to botton -i-e from parent class to child class because lets assume we have a variable of parent class
name (int a)
and this variable is used by its child classes... first contructor of parent class is executed so that this variable is 
allocated in the memory and so it is used by its child... just as beta baaap sa pehla ni a skta.
*/
// Destructor is Always called from Bottom to top -i-e from child class to parent class

/*
Destructor is Always called from Bottom to top -i-e from child class to parent class because lets assume we have a variable of parent class
name (int a)
and this variable is used by its child classes... first destructor of parent class is executed it means that now 
variable is destroyed... now if that variable was used by it child class... but now due to parent call destructor now that 
variable is no longer in the memory.. so this would be illeagal addressing of memory... so for this purpose first destructor
of child class is executed and then parent class...
*/


class University
{
protected:
string name="";
    
public:
    University()
    {
cout<<"Welcome to the bahria university Islamabad Campus"<<endl;
cout<<"Please enter you name : ";
getline(cin,name);
cout<<endl<<"Welcome "<<name<<endl;
    }
    ~University()
    {
cout<<"Destructor of class : University : is called"<<endl;
    }
};

class Departments  : public University
{
public:
    Departments() : University()
    {
        cout<<endl;
        cout<<name<<" There are 5 Departments in Bahria university.. Listed Below "<<endl;
        cout<<"1: SE\n2: EE\n3: CE\n4: Media Science\n5: Psycology"<<endl;
    }
    ~Departments() 
    {
        cout<<"Destructor of class : Departmets : is called "<<endl;
 
    }
};

class Faculty : public Departments
{
public:
    Faculty () : Departments()
    {
        cout<<name<<" SE have many faculty members ... etc (Checking) "<<endl;

    }
     ~Faculty()
     { cout<<"Destructor of class : faculty : is called"<<endl;}
};

int main()
{

    Faculty a;
    return 0;
}



