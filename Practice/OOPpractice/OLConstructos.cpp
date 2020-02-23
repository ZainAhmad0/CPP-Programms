#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int rollNumber;
    string name;

public:
    Student()
    {
        rollNumber = 0;
        name = "";
    }
    Student(int rollNum, string nameOfStudent)
    {
        rollNumber = rollNum;
        name = nameOfStudent;
    }
    void setInformation(int rollNum, string nameOfStudent)
    {
        rollNumber = rollNum;
        name = nameOfStudent;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    string getName()
    {
        return name;
    }
    ~Student()
    {
    }
};

Student takeStudentData()
{
    int rollNum;
    string name;
    Student obj;
    cout << endl
         << "Enter Roll Num : ";
    cin >> rollNum;
    cin.ignore();
    cout << "Enter Name :  ";
    getline(cin, name);
    obj.setInformation(rollNum, name);
    return obj;
}

int main()
{
    int numOfStudents;
    int choice = 0;
    int objCount = 0;
    Student classRepresentative(1223, "Sahil Nawaz");
    Student girlRepresentative(1345, "Areeb Ghauri");
    cout << "Number of students in class : ";
    cin >> numOfStudents;
    Student *obj = new Student[numOfStudents];
    while (choice != 4)
    {
        cout << "1: Enroll Student" << endl;
        cout << "2: Display CR & GR " << endl;
        cout << "3: Display All enrolled students" << endl;
        cout << "4: Exit " << endl;
        cin >> choice;
        if (choice == 1)
        {

            obj[objCount++] = takeStudentData();
            cout << endl
                 << "Student Enrolled Successfully" << endl
                 << endl;
        }
        else if (choice == 2)
        {
            cout << endl
                 << "CR Name : " << classRepresentative.getName() << endl;
            cout << "CR Roll Numer : " << classRepresentative.getRollNumber() << endl;
            cout << endl
                 << "GR : " << girlRepresentative.getName() << endl;
            cout << "GR : " << girlRepresentative.getRollNumber() << endl;
        }
        else if (choice == 3)
        {
            if (objCount != 0)
            {
                cout << "Currently Enrolled Students Are : " << objCount << endl;
                for (int loopVariable = 0; loopVariable < objCount; loopVariable++)
                {
                    cout << "Roll Number : " << obj[loopVariable].getRollNumber() << endl;
                    cout << "Name : " << obj[loopVariable].getName() << endl;
                    cout << endl;
                }
            }
            else
            {
                cout << "No Student Enrolled Currently" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Good Bye" << endl;
            delete[] obj;
        }
    }
}