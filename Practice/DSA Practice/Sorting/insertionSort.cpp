// complexity O(n2);
#include <iostream>
using namespace std;

template <class T>
void insertionSort(T array[], int size)
{
    T temp;
    int j;
    for (int i = 1; i < size; i++)
    {
        temp = array[i];
        j = i;
        while (j > 0 && array[j - 1] > temp)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
    }
}