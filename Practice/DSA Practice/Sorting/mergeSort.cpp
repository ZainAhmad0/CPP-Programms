// https://www.youtube.com/watch?v=jlHkDBEumP0
// learned from this video tutorial.

#include <iostream>
using namespace std;

template <class T>
void mergeSort(T array[], T tempArray[], int lowerBound, int upperBound)
{
    int mid;
    if (lowerBound > upperBound)
    {
        mid = ((lowerBound + upperBound) / 2);
        mergeSort(array, tempArray, lowerBound, mid);
        mergeSort(array, tempArray, mid + 1, upperBound);
        merge(array, tempArray, lowerBound, mid, upperBound);
    }
}

template <class T>
void merge(T arr[], T temp[], int lowerBound, int mid, int upperBound)
{
    int i, j, k;
    i = lowerBound;
    k = lowerBound;
    j = mid + 1;
    while (i <= mid && j <= upperBound)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=upperBound)
        {
            temp[k]=arr[j];
            k++; 
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
            k++; 
            i++;
        }
    }
    for(int p=lowerBound; p<=upperBound; p++)
    {
        arr[p]=temp[p];
    }
    
}