#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include <stdio.h>
#include <fstream>

using namespace std;

ofstream write_data ("Data Of Students.txt",fstream::app);//for student data file
ifstream read_data ("Data Of Students.txt",fstream::app); //for student data file

ofstream write_data_A ("Attendance Summary.txt",fstream::app);//for student attendance data file
ifstream read_data_A ("Attendance Summary.txt",fstream::app); //for student attendance data file

ofstream write_data_AR ("Attendance Report.txt",fstream::app);//for student attendance report file
ifstream read_data_AR ("Attendance Report.txt",fstream::app); //for student attendance report file

struct student_info // main structure of the Student array
{
    int student_id=0;
    float cgpa=0;
    int semester=0;
    string university_name="";
    string student_name="";
    string department_name="";
};



int Data_Validation_for_rollno_and_semester(int receiv) // this function is to validate the data for roll number and semester.
{
    int temp_value_for_validation_for_int=0;
    bool valid= false;

    do
    {
        if(receiv==1)
            cout<<"Enter Unique Student Id"<<endl;
        else if (receiv==0)
            cout<<"Enter Student Semester (e.g 7)"<<endl;
        else
            cout<<"Enter Credit Hours:   ";

        cin >> temp_value_for_validation_for_int;
        if (cin.good())
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // numeric_limits<streamsize>::max() sets the maximum number of characters to ignore
            if(receiv==1)
                cout << "Invalid input; please re-enter (roll no must be in numeric digits)." << endl;
            else if (receiv==0)
                cout << "Invalid input; please re-enter (Semester must be in numeric digits)." << endl;
            else
                cout << "Invalid input; please re-enter (Credit hours must be in numeric digits)." << endl;
        }
    }
    while (!valid);
    return temp_value_for_validation_for_int;
}



string Validate_Name(string temp_validation_string) // this function is mainly for the validation for the name and university string
{
    int lengh_of_string=0;
    int validatorr=0;
    int validator2=0;
    while(validatorr!=1)
    {
        lengh_of_string=temp_validation_string.length();
        validator2=0;
        for(int counter_loop11=0; counter_loop11<lengh_of_string; counter_loop11=counter_loop11+1)
        {
            if(!(((temp_validation_string[counter_loop11]>='a')&&(temp_validation_string[counter_loop11]<='z'))||((temp_validation_string[counter_loop11]>='A')&&(temp_validation_string[counter_loop11]<='Z'))||(temp_validation_string[counter_loop11]==' ')))

            {
                cout<<"Invalid Name, please re enter ... (Name & University must be in alphabets only)"<<endl;
                validator2=1;
                break;

            }
        }
        if(validator2==1)
        {
            temp_validation_string="";
            fflush(stdin);
            getline(cin,temp_validation_string);
        }
        else
        {
            validatorr=1;
        }
    }

    return temp_validation_string;
}



float Data_validation_for_Cgpa() // this function is to validate the data for  CGPA only.
{
    float temp_value_for_validation_float=0;
    bool valid= false;

    do
    {
        cout<<"Enter CGPA of Student"<<endl;
        cin >> temp_value_for_validation_float;
        if (cin.good())
        {
            //everything went well, we'll get out of the loop and return the value
            valid = true;
        }
        else
        {
            //something went wrong, we reset the buffer's state to good
            cin.clear();
            //and empty it
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // numeric_limits<streamsize>::max() sets the maximum number of characters to ignore
            cout << "Invalid input; please re-enter (CGPA must be in numeric digits)." << endl;
        }
    }
    while (!valid);
    return temp_value_for_validation_float;
}




void info_taker() // here main information is taken from the user about the student also the validation checks will be applied through functions here
{
    student_info information_of_student;
    int validator=0;
    if(write_data.is_open())
    {
        write_data.seekp(0,ios::end); // it is used that every time new data would be entered, it will start entering from the end line of the file.
        information_of_student.student_id=Data_Validation_for_rollno_and_semester(1);
        write_data<<information_of_student.student_id<<endl;
        cout<<"Enter Student Name "<<endl;
        fflush(stdin); // it is used to remove the data stored in keyboard buffer so that next time get line would work perfectly
        getline(cin, information_of_student.student_name);
        information_of_student.student_name=Validate_Name(information_of_student.student_name);
        write_data<<"Student Name: "<<information_of_student.student_name<<endl;
        cout<<"Enter Student Department"<<endl;
        fflush(stdin);
        getline(cin, information_of_student.department_name);
        write_data<<"Student Department: "<<information_of_student.department_name<<endl;
        cout<<"Enter Student University "<<endl;
        fflush(stdin);
        getline(cin, information_of_student.university_name);
        information_of_student.university_name=Validate_Name(information_of_student.university_name);
        write_data<<"Student University: "<<information_of_student.university_name<<endl;
        information_of_student.cgpa=Data_validation_for_Cgpa();

        while(validator!=1) // this is for validation of CGPA ...
        {

            if(information_of_student.cgpa>0 && information_of_student.cgpa<=4)
            {

                write_data<<"Student CGPA: "<<information_of_student.cgpa<<endl;
                validator=1;
                break;
            }
            else
            {
                cout<<"CGPA must be in (0-4) Figure ... Please re enter correctly"<<endl;
                information_of_student.cgpa=Data_validation_for_Cgpa();
            }

        }
        validator=0;
        information_of_student.semester=Data_Validation_for_rollno_and_semester(0);
        while(validator!=1)   // for validation of semester inner condition that sem must be between 1-8
        {

            if( information_of_student.semester>0 &&  information_of_student.semester<9)
            {

                write_data<<"Student Semester: "<< information_of_student.semester<<endl;
                validator=1;
                break;
            }
            else
            {
                cout<<"Semester must be in between 1-8 digits ... Please re enter correctly"<<endl;
                information_of_student.semester=Data_Validation_for_rollno_and_semester(0);
            }

        }

        cout<<endl;
    }
    else
        cout<<"File is not opened"<<endl;
}

int lenth_of_file_finder()  // it will find the number of lines in the files, so that that number of strings would be created to load all data.
{
    int taker_1;
    taker_1=0;
    string temp5="";
    ifstream read_data ("Data Of Students.txt",fstream::app);
    while(getline(read_data,temp5))
        ++taker_1;
    return taker_1;

}

int absent_students=0;
int present_students=0;
const string temp_1="*****";


char char_validation(int num)
{

    char temp_char;
    cin>>temp_char;

    for(int loopvar=1; loopvar!=0; loopvar++)
    {
        fflush(stdin);
        if  ( (temp_char=='p') || (temp_char=='P')  || (temp_char=='a') || (temp_char=='A') )
        {
            loopvar=-1;

        }
        else
        {
            cout<<"\nInvalid Marking... Please re-mark attendance of #"<< num <<" No. Student correctly :    ";
            cin>>temp_char;
        }

    }



    cout<<endl;
    if(temp_char=='P' || temp_char=='p')
        present_students++;
    else if (temp_char=='a' || temp_char=='A')
        absent_students++;

    return temp_char;
}


void record_maintain_attendence(string date_1, float credit_hrs)
{
  ofstream write_data_AR ("Attendance Report.txt",fstream::app);
  write_data_AR<<date_1<<endl;
  write_data_AR<<"Credit Hours Are: "<<credit_hrs<<endl;
  write_data_AR<<"Number Of Present Students: "<<present_students<<endl;
   write_data_AR<<"Number Of Absent Students: "<<absent_students<<endl;
   write_data_AR<<"*****"<<endl;
   present_students=0;
   absent_students=0;

}


void Mark_Attendance_of_students()
{
    ifstream read_data ("Data Of Students.txt",fstream::app);
    ofstream write_data_A ("Attendance Summary.txt",fstream::app);
    string date="";
    int cr_hrs;
    fflush(stdin);
    cout<<"Enter Date Of which you want to mark Attendance (DD/MM/YY)"<<endl;
    getline(cin,date);
    fflush(stdin);

    cr_hrs=Data_Validation_for_rollno_and_semester(5);
    write_data_A<<date<<endl;
    write_data_A<<"Credit Hours Are: "<<cr_hrs<<endl;

    cout<<"\n\n               For Marking Present: P (or) p    &    For Marking Absent: A (or) a \n"<<endl;
    string temp_str="";
    string total="";
    int lenth_of_file=0;
    lenth_of_file=lenth_of_file_finder();
    cout<<"\nTotal Students: "<<(lenth_of_file/6)<<endl<<endl;
    char attendance_char;
    for(int initial=0; initial<(lenth_of_file/6); initial++)
    {

        cout<<initial+1<<". ";
        getline(read_data, temp_str);
        total=total+temp_str+"  ";
        cout<<"Enrollment Num: "<<temp_str<<"   &   ";
        getline(read_data, temp_str);
        total=total+temp_str;
        cout<<temp_str<<"   ->    ";
        attendance_char=char_validation(initial+1);
        write_data_A<<initial+1<<": Enrollment Num: "<<total<<"     |->     "<<attendance_char<<endl;
        total="";

        for(int initial_1=0; initial_1<4; initial_1++)
        {
            getline(read_data, temp_str);
        }

    }
    record_maintain_attendence(date,cr_hrs);
    total="*****";
    write_data_A<<total<<endl;

}

void Displayer_List_of_students()
{
    ifstream read_data ("Data Of Students.txt",fstream::app);
    string temp_str="";
    int lenth_of_file=0;
    lenth_of_file=lenth_of_file_finder();
    cout<<"\nCurrent Number of students enrolled: "<<(lenth_of_file/6)<<endl<<endl;
    for(int initial=0; initial<(lenth_of_file/6); initial++)
    {
        cout<<initial+1<<". ";
        getline(read_data, temp_str);
        cout<<"Enrollment Num: "<<temp_str<<"   &   ";
        getline(read_data, temp_str);
        cout<<temp_str<<endl;
        for(int initial_1=0; initial_1<4; initial_1++)
        {
            getline(read_data, temp_str);
        }

    }
}

void Show_Marked_Attendance_of_students()
{
    int validatorr=0;
    string checker="";
    ifstream read_data_A ("Attendance Summary.txt",fstream::app);
    string temp="";
    cout<<"Enter Date (DD/MM/YY) of which you want to check attendance:   "<<endl;
    fflush(stdin);
    getline(cin,temp);
    cout<<endl;
    while(!read_data_A.eof())
    {
        fflush(stdin);
        getline(read_data_A,checker);
        if(checker==temp)
        {
            while(checker!=temp_1)
            {

                cout<<checker<<endl<<endl;
                getline(read_data_A,checker);
                validatorr=1;
            }
            break;
        }
    }
    if(validatorr==0)
        cout<<"No attendance record is stored against the entered date "<<endl;



}


void Show_Attendance_Report_of_students()
{
    ifstream read_data_AR ("Attendance Report.txt",fstream::app);
    int option=0;
    string temporary="";
cout<<"\n1: Show List of Marked Attendance Dates "<<endl;
cout<<"2: Search by date\n"<<endl;
cout<<"Please Enter Your choice:     ";
cin>>option;

if(option==1)
{
    while(!read_data_AR.eof())
    {
        getline(read_data_AR,temporary);
        cout<<temporary<<endl;
        for(int initial=0; initial<4; initial++)
            getline(read_data_AR,temporary);
    }
}
else if(option==2)
{
    ifstream read_data_AR ("Attendance Report.txt",fstream::app);
    int validatorr=0;
   fflush(stdin);
   string temp_date="";
   string checker="";
   cout<<"\nEnter Date (DD/MM/YY) :     ";
   getline(cin,temp_date);
   cout<<endl;
       while(!read_data_AR.eof())
    {
        fflush(stdin);
        getline(read_data_AR,checker);
        if(checker==temp_date)
        {
            while(checker!=temp_1)
            {

                cout<<checker<<endl;
                getline(read_data_AR,checker);

            }
            validatorr=1;
            break;
        }
    }
    if(validatorr==0)
        cout<<"No attendance record is stored against the entered date "<<endl;


}
else
cout<<"\nInvalid Option Entered ... "<<endl;


}





void initial_menu_displayer_2()
{
    cout<<"\n\n\t\t\t------- Welcome to CP Class students attendance system -------"<<endl;
}



int initial_menu_displayer_1()
{
    int choice;
    cout<<"1. Enroll student"<<endl;
    cout<<"2. Display list of students"<<endl;
    cout<<"3. Mark attendance"<<endl;
    cout<<"4. View attendance"<<endl;
    cout<<"5. View attendance report\n"<<endl;
    cout<<"Please type option to perform an action :    ";
    cin>>choice;
    cout<<endl<<endl;
    return choice;
}

int main()
{
    int choice;
    initial_menu_displayer_2();
    do
    {
        choice=initial_menu_displayer_1();
        switch(choice)
        {
        case 1:
        {
            info_taker();
            break;
        }
        case 2:
        {
            Displayer_List_of_students();
            break;
        }
        case 3:
        {
            Mark_Attendance_of_students();
            break;
        }
        case 4:
        {
            Show_Marked_Attendance_of_students();
            break;
        }
        case 5:
        {
            Show_Attendance_Report_of_students();
            break;
        }



        }
        cout<<"\nPress Any digit to go back to main menu or 0 to exit:     ";
        cin>>choice;
        cout<<endl;
    }
    while(choice!=0);
    return 0;
}
