/*
#include<iostream>
#include<string>
#include<fstream>
#include<iostream>
using namespace std;
class Write
{
protected:
	string data;
	char ch;
	int count;
public:
    Write(){
        data="";
        count=0;
    }
	void writeData();
};
void Write::writeData()
{
	ofstream myfile;
	myfile.open("Data.txt");
	{
		cout << "enter the data :";
        fflush(stdin);
		getline(cin, data);	
        fflush(stdin);	
		myfile << data ;
        fflush(stdin);
	}
	myfile.close();
}
class Read :public Write
{
public:
	void readData();
};
void Read::readData()
{
	ifstream myfile1;
	myfile1.open("Data.txt",ios::in);
	while (true)
	{
		myfile1.get(ch);
        if((myfile1.eof()))
        break;
		count++;
		cout << ch << endl;
        
	}
	myfile1.close();
	cout << "There are total " << count << " characters " << endl;

}
int  main()
{
	cout << "Zain Ahmad - 037 " << endl;
	Read obj1;
	obj1.writeData();
	obj1.readData();
}
*/
/*
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Student
{
private:
	Student structure[5];
	string name;	int age;	float cgpa;	string dob;	string bplace;
public:
	void getData();
	void showData();

};
void Student :: getData(){

	for (int i = 0; i < 5; i++)
	{
		cout << "enter name of student: ";
		cin>>structure[i].name;
		cout << "enter age:  ";
		cin>>structure[i].age;
		cout << "enter cgpa:  ";
		cin>>structure[i].cgpa;
		cout << "enter birth place:  ";
		cin>>structure[i].dob;
		cout << "enter date of birth:  ";
		cin>>structure[i].bplace;
	}

}
void Student :: showData(){
	ofstream a;
	a.open("man.txt");
	for (int i = 0; i < 5; i++)
	{
		a << structure[i].name<<endl;
		a << structure[i].age<<endl;
		a << structure[i].cgpa<<endl;
		a << structure[i].dob<<endl;
		a << structure[i].bplace<<endl;	}
	a.close();


}
int main()
{	
	cout << "Zain Ahmad &  01-131192-037"<<endl;
	Student obj1;
	obj1.getData();
	obj1.showData();
}
*/
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	cout << "Zain Ahmad &  01-131192-037\n";
	int a[4];
	int b[4];
	a[0] = 66;
	a[1] = 33;
	a[2] = 16;
	b[0] = 13;
	b[1] = 29;
	b[2] = 12;
	ofstream obj;
	obj.open("a.txt");
	for (int i = 0; i < 3; i++)
	{
		obj << a[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			obj << endl;
		}
		obj << b[i] << "\t";
	}
	obj << endl
		<< " ..  ..  ..  ..  ..";
	obj.close();
	cout << "file created\n";
	system("pause");
}
*/
/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void main()
{
	cout << "Zain Ahmad & 01-131192-037\n";
	int a[4];
	int b[4];
	ifstream obj;
	obj.open("a.txt");
	for (int i = 0; i < 3; i++)
	{
		obj >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		obj >> b[i];
	}
	obj.close();
	a[3] = a[0] + a[1] + a[2];
	b[3] = b[0] + b[1] + b[2];
	cout << a[0] << "\t" << a[1] << "\t" << a[2] << "\t" << a[3] << endl;
	cout << b[0] << "\t" << b[1] << "\t" << b[2] << "\t" << b[3] << endl;
	cout << "file created";
	system("pause");
}
*/
/*

#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout<<"Zain Ahmad 01-131192-037"<<endl;
	int a,b,c;
	cout<<"Enter a : ";
	cin>>a;
	cout<<"Enter b : ";
	cin>>b;
	cout<<"Enter c : ";
	cin>>c;
	try
	{
		if((a-b)!=0)
		{
			int d=c/(a-b); 
			cout<<"D : "<<d<<endl;			
		}
		else
		{
			throw string("Answer is infinity, because a-b=0");
		}		
	}
	catch(string exp)
	{
		cerr<<exp<<endl;		
	}
	return 0;
}

*/

#include <iostream>
#include <string>
using namespace std;

class Person
{

protected:
	char name[40];

public:
	void getName()
	{
		cout << "Enter name : ";
		cin >> name;
	}
	void putName()
	{
		cout << "Name is" << name << endl;
	}
	virtual void getData() = 0;
	virtual bool isOutstanding() = 0;
};

class Student : public Person
{
private:
	float gpa;

public:
	void getData()
	{
		Person::getName();
		cout << "\nEnter student’s GPA :";
		cin >> gpa;
	}
	bool isOutstanding()
	{
		return (gpa > 3.5) ? true : false;
	}
};

class Professor : public Person
{
private:
	int numPubs;

public:
	void getData()
	{
		Person::getName();
		cout << "\nEnter No.of Publications : ";
		cin >> numPubs;
	}
	bool isOutstanding()
	{
		return (numPubs > 100) ? true : false;
	}
};
int main()
{
	Person *persPtr[100];
	int n = 0;
	char choice;
	do
	{
		cout <<"\nEnter student or professor(s / p) :";
		cin >> choice;
		if (choice =='s')
		{
			persPtr[n] = new Student;
		}	
		else
			persPtr[n] = new Professor;
		persPtr[n++]->getData();
		cout <<"Enter Another ? (y / n) :";
		cin >> choice;
	} while (choice == 'y');
	
	for (int j = 0; j < n; j++)
	{
		persPtr[j]->putName();
		if (persPtr[j]->isOutstanding())
			cout <<"\nThis person is outstanding";
	}
	return 0;
}