#include <iostream>
#include "sorting.h"
using namespace std;

void displayArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % 100;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    Sorting obj;
    int compCount, moveCount;
    compCount = moveCount = 0;
    cout << "Arrays in ascending order" << endl;
    obj.selectionSort(arr1, size, compCount, moveCount);
    cout << "Selection sort" << endl;
    displayArray(arr1, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    compCount = moveCount = 0;
    obj.mergeSort(arr2, size, compCount, moveCount);
    cout << "Merge sort" << endl;
    displayArray(arr2, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    compCount = moveCount = 0;
    obj.quickSort(arr3, size, compCount, moveCount);
    cout << "Quick sort" << endl;
    displayArray(arr3, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    cout << "Radix sort" << endl;
    obj.radixSort(arr4, size);
    displayArray(arr4, size);
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    Sorting obj;
    cout << "Arrays in descending order" << endl;
    int compCount, moveCount;
    int temp1[size];
    compCount = moveCount = 0;
    obj.selectionSort(arr1, size, compCount, moveCount);
    obj.mergeSort(arr2, size, compCount, moveCount);
    obj.quickSort(arr3, size, compCount, moveCount);
    obj.radixSort(arr4, size);
    int j = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        temp1[j] = arr1[i];
        arr2[j] = arr3[j] = arr4[j] = temp1[j];
        j++;
    }
    arr1 = temp1;
    cout << endl
         << endl;
    cout << "Selection sort" << endl;
    displayArray(arr1, size);
    cout << "Merge sort" << endl;
    displayArray(arr2, size);
    cout << "Quick sort" << endl;
    displayArray(arr3, size);
    cout << "Radix sort" << endl;
    displayArray(arr4, size);
}

int main()
{
    int compCount, moveCount;
    compCount = moveCount = 0;

    const int size = 16;
    int arr1[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr2[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr3[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int arr4[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    Sorting obj;
    obj.selectionSort(arr1, size, compCount, moveCount);
    cout << "Selection sort" << endl;
    displayArray(arr1, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    compCount = moveCount = 0;
    obj.mergeSort(arr2, size, compCount, moveCount);
    cout << "Merge sort" << endl;
    displayArray(arr2, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    compCount = moveCount = 0;
    obj.quickSort(arr3, size, compCount, moveCount);
    cout << "Quick sort" << endl;
    displayArray(arr3, size);
    cout << "Comparison = " << compCount << " & Data moves = " << moveCount << endl;
    cout << "Radix sort" << endl;
    obj.radixSort(arr4, size);
    displayArray(arr4, size);
    return 0;
}
