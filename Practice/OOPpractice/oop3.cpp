#include<iostream>
#include<string.h>
using namespace std;


class Employee
{
    int employeeIdentificationNumber;
public:
    void setEmployeeIdentificationNumber(int);
    int getEmployeeIdentificationNumber();
};
void Employee :: setEmployeeIdentificationNumber(int a)
{
    employeeIdentificationNumber=a;
}
int Employee::getEmployeeIdentificationNumber()
{
    return employeeIdentificationNumber;
}
class Father
{
    int noOFSons;
public:
    void setNoOfSons(int);
    int getNoOfSons();  
};
void Father :: setNoOfSons(int a)
{
    noOFSons=a;
}
int Father :: getNoOfSons()
{
    return noOFSons;
}
class Student : public Father,public Employee
{
    string nameOFStudent;
    string currentUniversity;
    int studentId;
public:
    void setInfo(string,string,int);
    int getStudentId();
    string getName();
    string getCurrentUniversity();
};
void Student :: setInfo(string a,string b,int c)
{
    nameOFStudent=a;
    currentUniversity=b;
    studentId=c;
}
int Student :: getStudentId()
{
    return studentId;
}
string Student :: getName()
{
    return nameOFStudent;
}
string Student :: getCurrentUniversity()
{
    return currentUniversity;
}
