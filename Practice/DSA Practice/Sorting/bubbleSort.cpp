// complexity O(n2);
#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T array[], int size)
{
    T temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(array[i]<array[j])
            {
                temp = array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}
