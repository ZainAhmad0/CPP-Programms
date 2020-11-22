/*

// question 1
#include<iostream>
using namespace std;

int main()
{
    int num,num1;
    int reverseNum=0;
    cout<<"Please Enter an integer : ";
    cin>>num;
    while (num!=0)
    {
        num1=num%10;
        reverseNum=(reverseNum*10)+num1;
        num/=10;               
    }
    cout<<"Reverse Number is : "<<reverseNum<<endl;
    return 0;    
}
 
*/
/*
#include<iostream>
using namespace std;

int main()
{
    int firstTerm,secondTerm,nextTerm,range;
    firstTerm=0; // first term of fibonacci series
    secondTerm=1; //2nd term of fibonacci series
    cout<<"Enter your range : ";
    cin>>range;
    cout<<firstTerm<<", "<<secondTerm<<", "; //just to show the first two terms
    nextTerm=firstTerm+secondTerm;
    while(nextTerm<=range)
    {
        cout<<nextTerm<<", ";
        firstTerm=secondTerm;
        secondTerm=nextTerm;
        nextTerm=firstTerm+secondTerm;
    }
    return 0;    

}

*/

// question 5

/*

#include<iostream>
using namespace std;

int main()
{
    int size;
    float avgOfMarks=0;

    cout<<"Enter Number of students : ";
    cin>>size;
    int *marksOfStudents = new int [size];
    for(int i=0; i<size; i++)
    {
        cout<<"Enter Marks of Student "<<i+1<<" : ";
        cin>>marksOfStudents[i];
        avgOfMarks+=marksOfStudents[i];
    }
    avgOfMarks/=size;
    cout<<"Average of the entered marks are : "<<avgOfMarks<<endl;
    return 0;    

}

