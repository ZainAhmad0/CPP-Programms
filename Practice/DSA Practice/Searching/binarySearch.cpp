#include <iostream>
using namespace std;

template <class T>
int binarySearch(T Arr[], int size, T data) // works on sorted data
{

    int left, right, mid;
    left = 0;
    right = size - 1;
    while (left < right)
    {
        mid = ((left + right) / 2);
        if (Arr[mid] == data)
        {
            return mid;
        }
        else if (Arr[mid] < data)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

template <class T>
int binarySearchThroghRecursion(T Arr[], int left, int right, T data) // works on sorted data
{
    int mid;
    mid = ((left + right) / 2);
    if (left > right)
    {
        return -1;
    }
    if (Arr[mid] == data)
    {
        return mid;
    }
    else if (Arr[mid] < data)
    {
        return binarySearchThroghRecursion(Arr, mid + 1, right, data);
    }
    else
    {
        return binarySearchThroghRecursion(Arr, left, mid - 1, data);
    }
}