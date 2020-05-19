/*
#include <iostream>
using namespace std;

template <class T>
T returnAbsolute(T a)
{
    if(a<0){
        return (a*-1);
    }  
    return a;    
}
int main()
{
    int numInteger;
    float numFloat;
    long numLong;
    cout << "Zain Ahmad (037)" << endl;
    cout << "Enter Int : ";
    cin >> numInteger;
    cout << "Enter float : ";
    cin >> numFloat;
    cout << "Enter long : ";
    cin >> numLong;
    cout << "Absolute Int<"<<numInteger<<"> = " << returnAbsolute(numInteger) << endl;
    cout << "Absolute float<"<<numFloat<<"> = " << returnAbsolute(numFloat) << endl;
    cout << "Absolute long<"<<numLong<<"> = " << returnAbsolute(numLong) << endl;
    return 0;
}

*/
/*
#include <iostream>
using namespace std;

template <class T>
T returnAverage(T arr[], int length)
{
    T sum = 0;
    for(int i=0; i<length; i++){
        sum+=arr[i];
    }
    return (sum/length);
}
int main()
{
    int numInteger[5]={1,5,6,4,3};
    float numFloat[5]={3.7,8.3,99.55,6.87,44.5};
    long numLong[5]={666,777,88,444,567};
    cout << "Zain Ahmad (037)" << endl;
    cout << "Average of integer array = "<<returnAverage(numInteger,5)<<endl;
    cout << "Average of float array = " <<returnAverage(numFloat,5)<< endl;
    cout << "Average of longDataType array = "<<returnAverage(numLong,5)<< endl;
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

template <class T>
class FindFactorial
{
private:
    T num;
public:
    FindFactorial(){
        num=1;
    }
    T findFact(T numb){
        for(int i=1; i<=numb; i++){
            num=num*i;
        }
        return num;
    }
};
int main()
{
    cout << "Zain Ahmad (037)" << endl;
    cout<<"Enter a number : ";
    int number;
    cin>>number;
    FindFactorial<int> obj;
    cout<<"Factorial of "<<number<<" is = "<<obj.findFact(number)<<endl;
    return 0;
}
*/
#include <iostream>
using namespace std;

template<class T>
void printFibo(T a){
     cout << "Fibonacci Series: ";
    int t1 = 0, t2 = 1, nextTerm = 0;
     for (int i = 1; i <= a; ++i)
    {
        if(i == 1)
        {
            cout << " " << t1<<"    ";
            continue;
        }
        if(i == 2)
        {
            cout << t2 << "    ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << "    ";
    }
}

int main()
{
    int n;
    cout<<"Zain Ahmad 037"<<endl;
    cout << "Enter the number of terms: ";
    cin >> n;
    printFibo(n);
    return 0;
}