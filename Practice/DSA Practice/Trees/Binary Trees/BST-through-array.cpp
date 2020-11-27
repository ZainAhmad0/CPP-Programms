#include <iostream>
using namespace std;

template <class A>
class BinarySearchTree
{
private:
    A *array;
    int size;
    void inOrder(int index);
    void preOrder(int index);
    void postOrder(int index);

public:
    BinarySearchTree(int size);
    void insertElement(A x);
    bool searchElement(A x);
    void inOrder();
    void preOrder();
    void postOrder();
    int extendSize(int x);
};

template <class A>
int BinarySearchTree<A>::extendSize(int x)
{
    int value = 0;
    for (int y = 0; y < x + 1; y++)
    {
        value = (2 * value) + 2;
    }
    return value;
}

template <class A>
BinarySearchTree<A>::BinarySearchTree(int size1)
{
    size = extendSize(size1);
    array = new A[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = NULL;
    }
}

template <class A>
void BinarySearchTree<A>::insertElement(A x)
{
    int index = 0;
    while (true)
    {
        if (array[index] == NULL)
        {
            array[index] = x;
            cout << "Element Inserted" << endl;
            break;
        }
        else if (x < array[index])
        {
            index = ((2 * index) + 1);
        }
        else if (x >= array[index])
        {
            index = ((2 * index) + 2);
        }
    }
}

template <class A>
bool BinarySearchTree<A>::searchElement(A x)
{
    int index = 0;
    bool flag = false;
    while (true && index < size)
    {
        if (array[index] == x)
        {
            flag = true;
            break;
        }
        else if (x < array[index])
        {
            index = ((2 * index) + 1);
        }
        else if (x >= array[index])
        {
            index = ((2 * index) + 2);
        }
    }
    return flag;
}

template <class A>
void BinarySearchTree<A>::inOrder(int index)
{
    if (array[index] != NULL)
    {
        inOrder((2 * index) + 1);
        cout << array[index] << ", ";
        inOrder((2 * index) +2);
    }
}

template <class A>
void BinarySearchTree<A>::preOrder(int index)
{
    if (array[index] != NULL)
    {
        cout << array[index] << ", ";
        preOrder((2 * index) + 1);
        preOrder((2 * index) + 2);
    }
}

template <class A>
void BinarySearchTree<A>::postOrder(int index)
{
    if (array[index] != NULL)
    {
        postOrder((2 * index) + 1);
        postOrder((2 * index) + 2);
        cout << array[index] << ", ";
    }
}

template <class A>
void BinarySearchTree<A>::inOrder()
{
    inOrder(0); // as the root node is at 0
}

template <class A>
void BinarySearchTree<A>::preOrder()
{
    preOrder(0); // as the root node in at 0
}

template <class A>
void BinarySearchTree<A>::postOrder()
{
    postOrder(0); // as the root node in at 0
}

int main()
{
    BinarySearchTree<int> obj(20);
    obj.insertElement(2);
    obj.insertElement(-2);
    obj.insertElement(9);
    obj.insertElement(13);
    if(obj.searchElement(13))
    {
        cout<<"Element found"<<endl;
    }
    cout<<" ----------------Preorder traversal------------ "<<endl;
    obj.preOrder();
    cout<<endl;
    cout<<" ----------------Postorder traversal------------ "<<endl;
    obj.postOrder();
    cout<<endl;
    cout<<" ----------------Inorder traversal------------ "<<endl;
    obj.inOrder();
    cout<<endl;
    return 0;
}