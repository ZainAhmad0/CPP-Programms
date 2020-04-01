/*
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
    return (num)*(num);
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
    return ((num1)*(num1)*(num1));
}
};

int main()
{
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    int num1,num2;
    cout<<"Please enter a number for square : ";
    cin>>num1;
    cout<<"Please enter a number for Cube : ";
    cin>>num2;
    Cube obj(num1,num2);
    cout<<"Cube of the numbre is: "<<obj.calculateCube()<<endl;
    cout<<"Squre of number is : "<<obj.calculateSquare()<<endl;
    return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;

class Student
{
    int rollNo;
    string adress;
    string name;
public:
void getData();
};
void Student :: getData()
{
    cout<<"Enter Name : ";
    getline(cin,name);
    cin.clear();
    cout<<"Enter adress : ";
    getline(cin,adress);
    cin.clear();
    fflush(stdin);
    cout<<"Enter roll No : ";
    cin>>rollNo;
    fflush(stdin);
    cin.clear();
    fflush(stdin);
    
}
class InputMarks : public Student
{
    float marks[3];
    public:
    void inputMarks();
    void displayMarks();
    float calculateTotalMarksAndAverage();
};

float InputMarks :: calculateTotalMarksAndAverage()
{
    float sum,avg=0;
    sum=avg=0;
    for(int i=0; i<3; i++)
    {
        sum+=marks[i];
    }
    avg=sum/3;
    cout<<"Total Marks = "<<sum<<endl;
    cout<<"Average marks = "<<avg<<endl;
}
void InputMarks :: inputMarks()
{
    cout<<"Please Enter marks of subject 1 : ";
    fflush(stdin);
    cin>>marks[0];
    cout<<"Please Enter marks of subject 1 : ";
    fflush(stdin);
    cin>>marks[1];
    cout<<"Please Enter marks of subject 1 : ";
    fflush(stdin);
    cin>>marks[2];
}
void InputMarks :: displayMarks()
{
    for(int i=0; i<3; i++)
    {
        cout<<"Marks of subject "<<i+1<<" : "<<marks[i]<<endl;
    }
}

int main()
{
    cout<<"Zain Ahmd 01-131192-037"<<endl;
    InputMarks obj;
    obj.getData();
    obj.inputMarks();
    obj.displayMarks();
    obj.calculateTotalMarksAndAverage();
    return 0;
}

*/

#include<iostream>
#include<string>
using namespace std;

class Employee
{
    string name;
    int identificationNumber;
    public:
    void input();
    void show();
};
class Manager : public Employee
{
    string title;
    string salaryOfManager;
    Employee obj1;
    public:
    void input();
    void show();
};
class Scientist : public Employee
{
    int noOfArticles;
    string salaryOfScientist;
    Employee obj2;
    public:
    void input();
    void show();
};
class Clerks : public Employee
{
    int overTime;
    Employee obj3;
    public:
    void input();
    void show();
};
void Employee :: input()
{
    cout<<"Enter Name : ";
    cin.clear();
    getline(cin,name);
    cin.clear();
    cout<<"Enter Identificaiton Number : ";
    cin>>identificationNumber;
    cin.clear();
}
void Employee :: show()
{
    cout<<"Name Of Employee : "<<name<<endl;
    cout<<"Identificaiton Number of Employee : "<<identificationNumber<<endl;
}
void Manager :: input()
{
    obj1.input();
    cout<<"Enter Title : ";
    cin.clear();
    cin.ignore();
    getline(cin,title);
    cin.clear();
    cin.ignore();
    cout<<"Enter salary of Manager: ";
    getline(cin,salaryOfManager);
}
void Manager :: show()
{
    obj1.show();
    cout<<" Title : "<<title<<endl;
    cout<<"Salary of manager: "<<salaryOfManager<<endl;
}
void Scientist :: input()
{
    obj2.input();
    cin.clear();
    cout<<"Enter No of Articles Published : ";
    cin>>noOfArticles;
    cin.clear();
    cin.ignore();
    cout<<"Enter salary of Scientist: ";
    getline(cin,salaryOfScientist);
}
void Scientist :: show()
{
    obj2.show();
    cout<<"No of articles Published: "<<noOfArticles<<endl;
    cout<<"Salary of Scientist: "<<salaryOfScientist<<endl;
}
void Clerks :: input()
{
    obj3.input();
    cin.clear();
    cin.ignore();
    cout<<"Enter Overtime of Clerk : ";
    cin>>overTime;
}
void Clerks :: show()
{
    obj3.show();
    cout<<"Overtime of clerk: "<<overTime<<endl;
}

int main()
{
    cout<<"Zain Ahmad 01-131192-037"<<endl;
    Manager obj1,obj2;
    Scientist obj3;
    Clerks obj4;
    cout<<"Enter Data for First Manager "<<endl<<endl;
    obj1.input();
    cout<<   "          ***********************"<<endl<<endl;
    cout<<"Enter Data for Second Manager "<<endl<<endl;
    obj2.input();
    cout<<   "          ***********************"<<endl<<endl;
    cout<<"Enter data for Scientist "<<endl<<endl;
    obj3.input();
    cout<<"             **************************"<<endl<<endl;
    cout<<endl<<"Enter Data for Clerk "<<endl;
    obj4.input();
    cout<<"              *****************"<<endl;
    cout<<"Data For First Manager is "<<endl<<endl;
    obj1.show();
    cout<<endl<<"Data For Second Manager "<<endl<<endl;
    obj2.show();
    cout<<endl<<"Data For Scientist id :  "<<endl<<endl;
    obj3.show();
    cout<<endl<<"Data for clerk is : "<<endl;
    obj4.show();
    return 0; 

}




