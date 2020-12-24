#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    arr[0]=1;
    arr[1]=2;
    int i=0;
    while(arr[i]!='\0')
    {
        cout<<arr[i++]<<endl;
    }
    return 0;
}