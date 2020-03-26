//Zain Ahmad
//01-131192-037
//26th march 2020


#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str1,str2,str3;
    //str1 is for name
    //str2 is for adress    
    cout<<"Please, Enter you name : ";
    getline(cin,str1); // 1st
    cout<<"Please enter you address : ";
    getline(cin,str2);
    str1.append(" from "); //2nd
    // so that the output screen would show Zain ahmad "From" HIT Taxila cantt, or the alternative can be 
    // str3= str1 + " From " + str2; 
    cout<<"your information is : "<<endl;
    cout<<str1<<str2<<endl;  
    str3.assign("Bahria University"); // 3rd
    if(str3.empty()!=true) //3rd function
    cout<<"String 3 is not empty, it has length "<<str3.length()<<endl;
    return 0;
}