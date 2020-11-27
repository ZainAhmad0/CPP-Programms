#include <iostream>
using namespace std;

template <class A>
void swap(A *a, A *b) // to satisfy the heap property // heapify // this function would be used
{
    A temp = *a;
    *a = *b;
    *b = temp;
}

template <class A>
class MaxHeap
{
private:
    A *array;
    int capacity; // size of heap
    int count;    // Current number of elements in heap
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
    // to satisfy the heap property // heapify //
    // we are moving from top to bottom, this process is sometimes called percolate down.
    void percolateDown(int index);
    // Similarly, if we start heapifying from any other node to root
    // we can that process percolate up as move from bottom to top.
    void percolateUp(int index);
    // Deleting an element uses PercolateDown, and inserting an element uses PercolateUp.
    void resizeHeap(int capacity); // used to resize the heap when the heap is full

public:
    MaxHeap(int capacity);
    A getMaximum();
    A deleteMax();
    void insert(A data);
    bool replaceKey(A oldData, A newData); // replace the key or node
    void insert(A data);
    ~MaxHeap(); // for destroying the heap
};

template <class A>
MaxHeap<A>::MaxHeap(int capacity)
{
    this->capacity = capacity;
    array = new A[this - capacity];
    count = 0;
    for (int i = 0; i < this->capacity; i++)
    {
        array[i] = NULL;
    }
}

template <class A>
MaxHeap<A>::~MaxHeap()
{
    delete[] array;
}

template <class A>
int MaxHeap<A>::parent(int index)
{
    if (count == 0) // this means that empty heap
        return -1;
    else
        return ((index - 1) / 2);
}

template <class A>
int MaxHeap<A>::leftChild(int index)
{
    if (count == 0) // this means that empty heap
        return -1;
    else
        return (((index * 2) + 1));
}

template <class A>
int MaxHeap<A>::rightChild(int index)
{
    if (count == 0) // this means that empty heap
        return -1;
    else
        return ((index * 2) + 2)]);
}

template <class A>
A MaxHeap<A>::getMaximum()
{
    if (count == 0) // this means that empty heap
        return -1;
    else
        return (0); // because the maximum element of the heap is at root so arr[0] would be the maximum
}

template <class A>
void MaxHeap<A>::percolateDown(int index) // Deleting an element uses PercolateDown, and inserting an element uses PercolateUp.
{
    int max = index;
    int left = leftChild(index);
    int right = rightChild(index);
    if (left != NULL && array[left] > array[index])
    {
        max = left;
    }
    else if (right != NULL && array[right] > array[left])
    {
        max = right;
    }
    if (max != index)
    {
        swap(array[index], array[max]);
        percolateDown(max);
    }
}

template <class A>
void MaxHeap<A>::percolateUp(int index) // Deleting an element uses PercolateDown, and inserting an element uses PercolateUp.
{
    int parent = parent(index);
    if (array[index] > array[parent] &&parent ! = index)
    {
        swap(array[parent], array[index]);
        percolateUp(parent);
    }
}

template <class A>
bool MaxHeap<A>::replaceKey(A oldData, A newData)
{
    bool flag = false;
    for (int i = 0; i < count; i++)
    {
        if (array[i] == oldData)
        {
            array[i]=newData;
            percolateDown(i);
            flag = truel
            break;
        }
    }
    return flag;
}

template <class A>
A MaxHeap<A>::deleteMax()
{
    if (count == 0)
    {
        cout << "Empty heap" << endl;
        return NULL;
    }
    A tempData = array[0];
    array[0] = array[count - 1];
    count--;
    percolateDown(0);
    return tempData;
}

template <class A>
void MaxHeap<A>::insert(A data)
{
    if (count == capacity)
    {
        resizeHeap(capacity);
    }
    array[count] = data;
    percolateUp(count); // to satisfy heap property // heapify
    count++;
}

template <class A>
void MaxHeap<A>::resizeHeap(int capacity) // used to resize the heap when the heap is full
{
    int *arrayOld = array;
    array = new A[capacity * 2];
    for (int i = 0; i < capacity; i++)
    {
        array[i] = arrayOld[i];
    }
    this->capacity = (capacity * 2);
    delete[] arrayOld;
    return;
}

int main()
{
}