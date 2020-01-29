// with data validation & structures,strings,dynamic arrays,file handling,pointers (Student management system)
#include <limits>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>


using namespace std;
ofstream write_data ("DataOfStudent.txt",fstream::app);
ifstream read_data ("DataOfStudent.txt",fstream::app);



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
                cout<<"Enter Number of students"<<endl;

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
                cout << "Invalid input; please re-enter (Number of students must be in integer value)." << endl;
        }
    }
    while (!valid);
    return temp_value_for_validation_for_int;
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



struct student_info // main structure of the Student array
{
    int student_id=0;
    float cgpa=0;
    int semester=0;
    string university_name="";
    string student_name="";
    string department_name="";
};

int choice=1;
int length_finder(student_info *receiver) // this function is to find the length which receivers objects address which is stored
{
    int length_var=0;
    while(receiver->student_id!='\0')
    {
        length_var++;
        receiver++;
    }
    return length_var;
}
int count1=0;
void info_taker(student_info *taker) // here main information is taken from the user about the student also the validation checks will be applied through functions here
{
    int validator=0;
    if(write_data.is_open())
    {
        write_data.seekp(0,ios::end); // it is used that every time new data would be entered, it will start entering from the end line of the file.
        taker->student_id=Data_Validation_for_rollno_and_semester(1);
        write_data<<taker->student_id<<endl;
        cout<<"Enter Student Name "<<endl;
        fflush(stdin); // it is used to remove the data stored in keyboard buffer so that next time get line would work perfectly
        getline(cin, taker->student_name);
        taker->student_name=Validate_Name(taker->student_name);
        write_data<<"Student Name: "<<taker->student_name<<endl;
        cout<<"Enter Student Department"<<endl;
        fflush(stdin);
        getline(cin, taker->department_name);
        write_data<<"Student Department: "<<taker->department_name<<endl;
        cout<<"Enter Student University "<<endl;
        fflush(stdin);
        getline(cin, taker->university_name);
        taker->university_name=Validate_Name(taker->university_name);
        write_data<<"Student University: "<<taker->university_name<<endl;
        taker->cgpa=Data_validation_for_Cgpa();

        while(validator!=1) // this is for validation of CGPA ...
        {

            if(taker->cgpa>=0 && taker->cgpa<=4)
            {

                write_data<<"Student CGPA: "<<taker->cgpa<<endl;
                validator=1;
                break;
            }
            else
            {
                cout<<"CGPA must be in (0-4) Figure ... Please re enter correctly"<<endl;
                taker->cgpa=Data_validation_for_Cgpa();
            }

        }
        validator=0;
        taker->semester=Data_Validation_for_rollno_and_semester(0);
        while(validator!=1)   // for validation of semester inner condition that sem must be between 1-8
        {

            if(taker->semester>0 && taker->semester<9)
            {

                write_data<<"Student Semester: "<<taker->semester<<endl;
                validator=1;
                break;
            }
            else
            {
                cout<<"Semester must be in between 1-8 digits ... Please re enter correctly"<<endl;
                taker->semester=Data_Validation_for_rollno_and_semester(0);
            }

        }

        cout<<endl;
    }
    else
        cout<<"File is not opened"<<endl;
}
void show(student_info *showw) // it is used to show the student information
{
    cout<<"Name : "<<showw->student_name<<endl;
    cout<<"ID : "<<showw->student_id<<endl;
    cout<<"University : "<<showw->university_name<<endl;
    cout<<"Department : "<<showw->department_name<<endl;
    cout<<"CGPA : "<<showw->cgpa<<endl;
    cout<<"Semester : "<<showw->semester<<endl;
}
void delete_student(student_info* record_delete, int initialize, int length) // this function is used when the user want to delete the student information
{
    for(int loop_var_for_delete=initialize; loop_var_for_delete<length-1; loop_var_for_delete++)
    {
        record_delete[loop_var_for_delete]=record_delete[loop_var_for_delete+1];      // the whole  student object would be deleted here
    }
    record_delete[length-1].student_id='\0'; // here the \0 is placed in the slot of memory where the record is deleted
}


int lenth_of_file_finder()  // it will find the number of lines in the files, so that that number of strings would be created to load all data.
{
    int taker_1;
    taker_1=0;
    string temp5="";
    ifstream read_data("DataOfStudent.txt");
    while(getline(read_data,temp5))
        ++taker_1;
    return taker_1;

}


int delete_student1(int id) //This function will get all the data from the file and store it into the arrays of strings and after operations the new data will be written back to it
{

    int counter_for_file;
    counter_for_file=0;
    string searcher_id="";
    searcher_id=to_string(id);
    int lenth_of_file;
    lenth_of_file=0;
    lenth_of_file=lenth_of_file_finder();
    string *Data_Of_Student = new string [lenth_of_file];
    int check_for_condition;
    check_for_condition=0;
    ifstream read_data ("DataOfStudent.txt",fstream::app);
    if(read_data.is_open())
    {
        for(counter_for_file=0; counter_for_file<lenth_of_file; counter_for_file++)
        {
            getline(read_data, Data_Of_Student[counter_for_file]);

        }  // this loop will fill all the data of the files in the strings.

    }
    else
    {
        cout<<"Error reading file";
        return 0;
    }
    for(int loop_variable1=0; loop_variable1<lenth_of_file; loop_variable1=loop_variable1+6)
    {
        if(Data_Of_Student[loop_variable1]==searcher_id)
        {
            for(int inner_loop_var=loop_variable1; inner_loop_var<(loop_variable1+6); inner_loop_var=inner_loop_var+1)
            {
                // Data_Of_Student[inner_loop_var]=""; // this can also be used instead of clear function
                Data_Of_Student[inner_loop_var].clear();
            }
            cout<<"Record is Found and is successfully deleted from the System"<<endl<<endl;
            ++check_for_condition;
            break;
        }

    }

    if(check_for_condition==0)
    {
        cout<<"The Entered Record is not found in the system"<<endl;
        delete []Data_Of_Student; // if record is not found it will delete the all strings
        return 0;
    }

    ofstream write_data("DataOfStudent.txt", ios::trunc); // this will delete all the contents from the file

    for(int counter_var_loop=0; counter_var_loop<lenth_of_file; counter_var_loop=counter_var_loop+1)
    {
        if(Data_Of_Student[counter_var_loop]=="")
        {
            counter_var_loop=counter_var_loop+5;
        }
        else
        {
            write_data<<Data_Of_Student[counter_var_loop]<<endl;
        }
    }

    delete []Data_Of_Student;

    return 0;



}

void Initial_menu_displayer()
{
    cout<<"1. Create Student profile"<<endl;
    cout<<"2. Search Student"<<endl;
    cout<<"3. Delete Student Record"<<endl;
    cout<<"Please type option to perform an action:"<<endl;
}

void Initial_menu_displayer_2()
{
    cout<<"1. Search By ID (Will only return 1 student) "<<endl;
    cout<<"2. List Number of Students (With selecting option 2 list of all students will be displayed)"<<endl;
}

int main()
{
    int num=0;
    num=Data_Validation_for_rollno_and_semester(7);
    student_info *info = new student_info[num];// pointer array of user defined data type created here
    for(int loop_var=0; loop_var<num; loop_var++)
        info[loop_var].student_id='\0'; // loop_counter_file am adding \0 to id of each object which will help to me to calculate the length , like how many students have been entered in the objects.
    cout<<"Welcome to student management system    (Max "<<num<<" Students)!!!"<<endl;
    do
    {
        int option,option2,search_id;
        option=option2=search_id=0;
        Initial_menu_displayer();
        cin>>option;
        cout<<endl;
        switch(option) // using switch statement instead of if-else for optimization
        {
        case 1:
        {
            for(int loop_counter=0; loop_counter<num; loop_counter++)
            {
                if(info[loop_counter].student_id=='\0')
                {
                    info_taker(&info[loop_counter]);
// here the information would be taken from the user and loop_counter am using condition so that where first free (useful when the record is deleted, on that memory slow \0 is placed) \0 is placed in memory on that place the record would be stored
                    break;
                }
            }
            break;
        }
        case 2:
        {
            Initial_menu_displayer_2();
            cin>>option2;
            int loop_variable,loop_counter,breaker;
            loop_variable=loop_counter=breaker=0;
            loop_variable=length_finder(info);
            if(option2==1)
            {
                cout<<"Enter Student Id "<<endl;
                cin>>search_id;
                for( loop_counter=0; loop_counter<loop_variable; loop_counter++)
                {
                    if(info[loop_counter].student_id==search_id)
                    {
                        breaker=1;
                        break;
                    }
                }
                if(breaker==1)
                {
                    show(&info[loop_counter]);
                }
                else
                    cout<<"Record Does Not exists in the system"<<endl;
            }
            else if(option2==2)
            {
                for(int counter_for_loop=0; counter_for_loop<loop_variable; counter_for_loop++)
                    cout<<"Student ID: "<<info[counter_for_loop].student_id<<endl; // list of students would be displayed
            }
            break;
        }
        case 3:
        {
            int loop_counter,loop_variable,breaker1,search_id1;
            loop_counter=loop_variable=breaker1=search_id1=0;
            cout<<"Enter ID to delete record"<<endl;
            cin>>search_id1;
            delete_student1(search_id1);  // deletion in file
            loop_variable=length_finder(info);
            for(loop_counter=0; loop_counter<loop_variable; loop_counter++)
            {
                if(info[loop_counter].student_id==search_id1)
                {
                    breaker1=1;
                    break;
                }
            }
            if(breaker1==1)
            {
                delete_student(info,loop_counter,loop_variable);
            }


            break;
        }
        }
        cout<<"Press 0 to exit or other digit to go back to main menu"<<endl;
        cin>>choice;
        cout<<endl;
    }
    while(choice!=0);
    return 0;
}
