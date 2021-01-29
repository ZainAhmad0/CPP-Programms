// complexity O(n2);
#include <iostream>
using namespace std;

template <class T>
void selectionSort(T array[], int size)
{
    // finds the smallest element in array and insert it at current position
    T temp;
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[i])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}
