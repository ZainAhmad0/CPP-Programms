// fastest sorting algorithm if programmed right

// complexity O(nlog2n);




// https://www.youtube.com/watch?v=QN9hnmAgmOc 
// learnt from here 

#include <iostream>
using namespace std;

template <class T>
void swap(T *first, T *second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <class T>
void quickSort(T array[], int lowerBound, int upperBound)
{
    if (upperBound > lowerBound)
    {
        int pivot = partition(array, lowerBound, upperBound);
        quickSort(array, lowerBound, pivot - 1);
        quickSort(array, pivot + 1, upperBound);
    }
}

template <class T>
int partition(T arr[], int lowerBound, int upperBound)
{
    int pivotPoint = arr[lowerBound];
    int left = lowerBound;
    int right = upperBound;
    while (right > left)
    {
        while (arr[left] <= pivotPoint)
        {
            left++;
        }
        while (arr[right] > pivotPoint)
        {
            right--;
        }
        if (right > left)
        {
            swap(arr[left], arr[right]);
        }
    }
    arr[lowerBound] = arr[right];
    arr[right] = pivotPoint;
    return right;
}
