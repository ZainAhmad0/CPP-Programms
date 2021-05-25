#include <iostream>
#include <stdlib.h>
#include "sorting.h"
#include <math.h>
#include <chrono>
using namespace std;

double datas[7][3];
double datam[7][3];
double dataq[7][3];
double datar[7];
double tempA[10];

void displayAnalysis()
{
}

void performanceAnalysis(int *arr1, int *arr2, int *arr3, int *arr4, const int size)
{
    Sorting obj;
    int compCount, moveCount;
    compCount = moveCount = 0;
    //double* data= new double[10];
    //SS
    auto start = chrono::high_resolution_clock::now();
    obj.selectionSort(arr1, size, compCount, moveCount);
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    tempA[0] = elapsed.count();
    tempA[1] = compCount;
    tempA[2] = moveCount;

    //MS
    compCount = moveCount = 0;
    start = chrono::high_resolution_clock::now();
    obj.mergeSort(arr2, size, compCount, moveCount);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    tempA[3] = elapsed.count();
    tempA[4] = compCount;
    tempA[5] = moveCount;
    //QS
    compCount = moveCount = 0;
    start = chrono::high_resolution_clock::now();
    obj.quickSort(arr3, size, compCount, moveCount);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    tempA[6] = elapsed.count();
    tempA[7] = compCount;
    tempA[8] = moveCount;
    //RS
    compCount = moveCount = 0;
    start = chrono::high_resolution_clock::now();
    obj.radixSort(arr4, size);
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    tempA[9] = elapsed.count();
}

void displayArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void dispPerfromance()
{
    int ate[] = {6000, 10000, 14000, 18000, 22000, 26000, 30000};
    cout << "-----------------------------------------" << endl;
    cout << "Analysis of Selection Sort" << endl;
    cout << "Array size\tElaped time\tcompCOunt\tmoveCount" << endl;
    for (int i = 0; i <= 7; i++)
    {
        cout << ate[i] << "\t       " << datas[i][0] << "\t        " << datas[i][1] << "    " << datas[i][2] << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array size\tElaped time\tcompCOunt\tmoveCount" << endl;
    for (int i = 0; i <= 7; i++)
    {
        cout << ate[i] << "\t       " << datam[i][0] << "\t    " << datam[i][1] << "\t    " << datam[i][2] << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array size\tElaped time\tcompCOunt\tmoveCount" << endl;
    for (int i = 0; i <= 7; i++)
    {
        cout << ate[i] << "\t     " << dataq[i][0] << "\t       " << dataq[i][1] << "\t            " << dataq[i][2] << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "Analysis of Radix Sort" << endl;
    cout << "Array size\tElaped time" << endl;
    for (int i = 0; i <= 7; i++)
    {
        cout << ate[i] << "\t\t" << datar[i] << endl;
    }
}

int main()
{

    int size;

    int j = 0;
    for (int i = 6000; i <= 30000; i += 4000)
    {
        size = i;
        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        int *arr4 = new int[size];
 
        for (int i = 0; i < size; i++)
        {
            arr1[i] = rand() % 5000;
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
            arr4[i] = arr1[i];
        }

        performanceAnalysis(arr1, arr2, arr3, arr4, size);

        datas[j][0] = tempA[0];
        datam[j][0] = tempA[3];
        dataq[j][0] = tempA[6];
        datas[j][1] = tempA[1];
        datam[j][1] = tempA[4];
        dataq[j][1] = tempA[7];
        datas[j][2] = tempA[2];
        datam[j][2] = tempA[5];
        dataq[j][2] = tempA[8];
        datar[j] = tempA[9];
        j++;
    }
    dispPerfromance();
    return 0;
}
