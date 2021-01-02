/*

1st

#include <iostream>
using namespace std;

int main()
{
    int *arr = new int[10];
    for(int i=0; i<10; i++)
    {
        cout<<"Enter "<<i+1<<" value : ";
        cin>>arr[i];
    }
    int *temp = new int;
    cout<<"Enter variale to find in array : ";
    cin>>*temp;
    bool flag=false;
    for(int i=0; i<10; i++)
    {
        if(arr[i]==*temp)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        cout<<"Present"<<endl;
    }
    else
    {
        cout<<"Not Present"<<endl;
    }
    return 0;
    

}

*/

/*

2nd

#include <iostream>
using namespace std;

int main()
{
    int *arr = new int[20];
    int noOfPostitive, noOfNegative, noOfEven, noOfOdd;
    noOfEven = noOfNegative = noOfPostitive = noOfOdd = 0;
    for (int i = 0; i < 20; i++)
    {
        cout << "Enter " << i + 1 << " value : ";
        cin >> arr[i];
        if (arr[i] >= 0)
            noOfPostitive++;
        else
            noOfNegative++;
        if (arr[i] % 2 == 0)
            noOfEven++;
        else
            noOfOdd++;
    }
    cout<<"No Of Positive Numbers Are : "<<noOfPostitive<<endl;
    cout<<"No Of Negative Numbers Are : "<<noOfNegative<<endl;
    cout<<"No Of Even Numbers Are : "<<noOfEven<<endl;
    cout<<"No Of Odd Numbers Are : "<<noOfOdd<<endl;
    cout<<endl;
}

*/

/*

3rd

#include <iostream>
using namespace std;

int main()
{
    int *arr = new int[10];
    for(int i=0; i<10; i++)
    {
        cout<<"Enter "<<i+1<<" value : ";
        cin>>arr[i];
    }
    int temp=0;
    for(int i=0; i<10; i++)
    {
        if(temp<arr[i])
        {
            temp=arr[i];
        }
    }
    cout<<"Largest Element is : "<<temp<<endl;
    return 0;
}

*/

/*

4rd

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int rows, cols;
    float sum=0;
    cout << "Enter Rows : ";
    cin >> rows;
    cout << "Enter Cols : ";
    cin >> cols;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value arr["<<i<<"]["<<j<<"] value : ";
            cin >> arr[i][j];
            sum+=arr[i][j];
        }
    }
    float norm=sqrt(sum);
    cout<<"Eulidean Norm is : "<<norm<<endl;
    return 0;
}

*/

/*

5th

#include <iostream>
#include <math.h>
using namespace std;

float calculateNorm(int **array, int rows, int cols)
{
    float sum=0;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];

    arr = array;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value arr[" << i << "][" << j << "] value : ";
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    return sqrt(sum);
}

int main()
{
    int rows, cols;
    float sum = 0;
    cout << "Enter Rows : ";
    cin >> rows;
    cout << "Enter Cols : ";
    cin >> cols;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
        arr[i] = new int[cols];
    float norm = calculateNorm(arr,rows,cols);
    cout << "Eulidean Norm is : " << norm << endl;
    return 0;
}

*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a = 20;
    int b = 30;
    int *ptr;
    ptr = &b;
    *ptr = 55;
    cout << b << endl;
}