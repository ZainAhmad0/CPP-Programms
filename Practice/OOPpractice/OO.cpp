// OOP Assignment No # 02
// Zain Ahmad (01-131192-037)
// Muhammad Saad (01-131192-020)

#include<iostream>
#include<string>
using namespace std;

class Bahria
{
    string nameOfMember;
    int idOFMember;
    float cellaryOfMember;
    string designationOfMember;
    string joiningDateOfEmployee;
    float totalTax;

public:
    Bahria();
    void setInformation(int, int, string, string, string);
    string getNameOFMember();
    int getId();
    string getDesignation();
    string getJoiningDate();
    float getCellary();
    float getTotalTax();
    Bahria operator + (Bahria);
};

Bahria::Bahria()
{
    cellaryOfMember=0;
    idOFMember=0;
    nameOfMember="";
    designationOfMember="";
    joiningDateOfEmployee="";
    totalTax=0;
}

void Bahria :: setInformation(int pay, int id, string name, string designation, string joiningDate)
{
    cellaryOfMember=pay;
    idOFMember=id;
    nameOfMember=name;
    designationOfMember=designation;
    joiningDateOfEmployee=joiningDate;
}

Bahria Bahria :: operator+(Bahria obj)
{
    cout<<"May ALLAH (SWT) Protect us from COVID-19"<<endl;
    Bahria obj1;
    float tax=0;
    tax=obj.getCellary();
    tax=(tax/100)*2;  // tax of this particular employee will be calculated
    totalTax=totalTax+tax; // then the tax of this employee will be added to whole amount (total tax).
    obj1.totalTax=totalTax;
    return obj1;
}

string Bahria::getNameOFMember()
{
    return nameOfMember;
}

int Bahria :: getId()
{
    return idOFMember;
}

string Bahria :: getDesignation()
{
    return designationOfMember;
}

string Bahria :: getJoiningDate()
{
    return joiningDateOfEmployee;
}

float Bahria :: getCellary()
{
    return cellaryOfMember;
}

float Bahria :: getTotalTax()
{
    return totalTax;
}

int main()
{
    int choice,countMembers;
    choice=countMembers=0;
    float totalTax=0;
    int id;
    float cellary;
    string name,designation,joiningDate;
    Bahria obj[20]; // this is the total 20 employee's sir 
    cout<<"                 Welcome To Management Staff Of Bahria               "<<endl<<endl<<endl;
    do
    {
        cout<<"1: Enroll management staff member in Bahria"<<endl;
        cout<<"2: Check Total number of enrolled members and their names"<<endl;
        cout<<"3: Calculate tax collected of one month from the pays of management staff members"<<endl;
        cout<<"4: Exit"<<endl;
        cout<<endl<<"Please enter you chocie :  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"You Can Only Enroll maximum 20 staff members only"<<endl;
            cout<<"Current number of staff members enrolled till now : "<<countMembers<<endl<<endl;
            if(countMembers<20)
            {
                cout<<"Enter Name : ";
                cin.ignore();
                getline(cin,name);
                cout<<"Enter Designation of staff member : ";
                cin.ignore();
                getline(cin,designation);
                cout<<"Enter joining Date : ";
                cin.ignore();
                getline(cin,joiningDate);
                cout<<"Enter ID of employee : ";
                cin>>id;
                cout<<"Enter cellary of Employee : ";
                cin>>cellary;
                obj[countMembers++].setInformation(cellary,id,name,designation,joiningDate);
                cout<<"Employee enrolled successfully"<<endl<<endl;
            }
            else
            {
                cout<<"Maximum length of enrolling staff members exceeded, sorry you cannot not enroll more that 20"<<endl;
            }
            break;
        }
        case 2:
        {
            cout<<endl<<"Current number of enrolled members are : "<<countMembers<<endl; 
            for(int count=0; count<countMembers; count++)
            {
                cout<<count+1<<": "<<obj[count].getNameOFMember()<<endl;
            }
            cout<<endl;
            break;
        }
        case 3:
        {
            cout<<"Currently "<<countMembers<< " are Enrolled in Bahria "<<endl;
            cout<<"Tax ratio for Bahria is 2 percent of Employee's Cellary"<<endl<<endl;
            Bahria obj1; // this is for calculaing the tax of the total employee's sir.
            for(int count=0; count<=countMembers; count++)
            {
                if(obj[count].getCellary()>35000)  // for each cellary greater than 35000, 2 percent tax would be applied
                {
                    obj1=obj1+obj[count];
                }
            }
            cout<<"Total Tax Calculated is : "<<obj1.getTotalTax()<<endl<<endl;
            break;
        }
        }
    }
    while (choice!=4);
    return 0;
}
