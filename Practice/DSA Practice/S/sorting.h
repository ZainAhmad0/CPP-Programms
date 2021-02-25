#include <iostream>
using namespace std;

class Sorting
{
private:
    void radixSortHelper(int *arr, int size, int exp)
    {
        int output[size];
        int i, count[10] = {0};

        for (i = 0; i < size; i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = size - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < size; i++)
            arr[i] = output[i];
    }

    void merge(int *arr, int *temp, int lowerBound, int mid, int upperBound, int &compCount, int &moveCount)
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
            compCount++;
            moveCount++;
            k++;
        }
        if (i > mid)
        {
            while (j <= upperBound)
            {
                temp[k] = arr[j];
                k++;
                j++;
                moveCount++;
            }
        }
        else
        {
            while (i <= mid)
            {
                temp[k] = arr[i];
                k++;
                i++;
                moveCount++;
            }
        }
        for (int p = lowerBound; p <= upperBound; p++)
        {
            arr[p] = temp[p];
        }
    }

    void mergeSortHelper(int *arr, int *temparr, int lowerBound, int upperBound, int &compCount, int &moveCount)
    {
        int mid;
        if (lowerBound < upperBound)
        {
            mid = ((lowerBound + upperBound) / 2);
            mergeSortHelper(arr, temparr, lowerBound, mid, compCount, moveCount);
            mergeSortHelper(arr, temparr, mid + 1, upperBound, compCount, moveCount);
            merge(arr, temparr, lowerBound, mid, upperBound, compCount, moveCount);
        }
    }

    void swap(int &first, int &second)
    {
        int temp = first;
        first = second;
        second = temp;
    }

    int partition(int *arr, int lowerBound, int upperBound, int &compCount, int &moveCount)
    {
        int pivotPoint = arr[lowerBound];
        int left = lowerBound;
        int right = upperBound;
        while (right > left)
        {
            while (arr[left] <= pivotPoint)
            {
                left++;
                compCount++;
            }
            while (arr[right] > pivotPoint)
            {
                right--;
                compCount++;
            }
            if (right > left)
            {
                swap(arr[left], arr[right]);
                moveCount += 3;
            }
        }
        arr[lowerBound] = arr[right];
        arr[right] = pivotPoint;
        moveCount += 2;
        return right;
    }

    void quickSortHelper(int *array, int lowerBound, int upperBound, int &compCount, int &moveCount)
    {
        if (upperBound > lowerBound)
        {
            int pivot = partition(array, lowerBound, upperBound, compCount, moveCount);
            quickSortHelper(array, lowerBound, pivot - 1, compCount, moveCount);
            quickSortHelper(array, pivot + 1, upperBound, compCount, moveCount);
        }
    }

public:
    void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
    {
        // finds the smallest element in arr and insert it at current position
        int temp;
        int min, m = 0;
        for (int i = 0; i < size; i++)
        {
            min = i;
            for (int j = i + 1; j < size; j++)
            {
                compCount++;
                if (arr[j] < arr[min])
                {
                    min = j;
                    m = 1;
                }
            }
            if (m)
            {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
                moveCount += 3;
                m = 0;
            }
        }
    }

    void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
    {
        int lowerBound = 0;
        int upperBound = size;
        int *tempArr = new int[size];
        mergeSortHelper(arr, tempArr, lowerBound, upperBound, compCount, moveCount);
    }

    void quickSort(int *arr, const int size, int &compCount, int &moveCount)
    {
        int lowerBound, upperBound;
        lowerBound = 0;
        upperBound = size;
        quickSortHelper(arr, lowerBound, upperBound, compCount, moveCount);
    }

    void radixSort(int *arr, const int size)
    {
        int mx;
        mx = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > mx)
                mx = arr[i];
        }

        for (int exp = 1; mx / exp > 0; exp *= 10)
            radixSortHelper(arr, size, exp);
    }
};