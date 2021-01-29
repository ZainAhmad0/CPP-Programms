#include <iostream>
using namespace std;

int Binary(int x[], int n, int key)
{
    int low = 0;
    int mid;
    int hi = n - 1;
    while (low <= hi)
    {
        mid = (low + hi) / 2;
        if (key == x[mid])
            return (mid);
        if (key < x[mid])
            hi = mid - 1;
        else
            low = mid + 1;
    }
    low = mid + 1;
    return -1;
}

int main()
{
    int a = 10;
    cout << "Zain Ahmad 01-131192-037" << endl;
    int array[a];
    for (int i = 0; i < a; i++)
    {
        array[i] = rand() % 10000;
    }
    double dif;
    time_t start, end;
    time(&start);
    int b = Binary(array, a, 2324);
    time(&end);
    dif = difftime(end, start);
    cout << "Found at " << b << endl;
    cout << "Execution time  : " << dif << endl;
    return 0;
}