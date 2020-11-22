#include <iostream>
using namespace std;

template <class N>
struct Node
{
    N value;
    Node *left;
    Node *right;
};

template <class BT>
class BinaryTree
{

private:
    Node<BT> *root;
    void destroyTree(Node<BT> *leaf);
    void insert(BT key, Node<BT> *leaf);
    bool search(BT key, Node<BT> *leaf);
    void inorderPrint(Node<BT> *leaf);
    void postorderPrint(Node<BT> *leaf);
    void preorderPrint(Node<BT> *leaf);

public:
    BinaryTree();
    ~BinaryTree();
    void insert(BT key);
    bool search(BT key);
    void destroyTree();
    void inorderPrint();
    void postorderPrint();
    void preorderPrint();
};

template <class BT>
BinaryTree<BT>::BinaryTree()
{
    root = NULL;
}

template <class BT>
BinaryTree<BT>::~BinaryTree()
{
    destroyTree();
}

template <class BT>
void BinaryTree<BT>::insert(BT key)
{
    if (root != NULL)
    {
        insert(key, root);
    }
    else
    {
        Node<BT> *newNode = new Node<BT>();
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->value = key;
        root = newNode;
    }
}

template <class BT>
void BinaryTree<BT>::insert(BT key, Node<BT> *leaf)
{
    if (key < leaf->value)
    {
        if (leaf->left != NULL)
        {
            insert(key, leaf->left);
        }
        else
        {
            Node<BT> *newNode = new Node<BT>();
            newNode->left = newNode->right = NULL;
            newNode->value = key;
            leaf->left = newNode;
        }
    }
    else if (key >= leaf->value)
    {
        if (leaf->right != NULL)
        {
            insert(key, leaf->right);
        }
        else
        {
            Node<BT> *newNode = new Node<BT>();
            newNode->left = newNode->right = NULL;
            newNode->value = key;
            leaf->right = newNode;
        }
    }
}

template <class BT>
bool BinaryTree<BT>::search(BT key, Node<BT> *leaf)
{
    if (leaf != NULL)
    {
        if (key == leaf->value)
        {
            return true;
        }
        if (key < leaf->value)
        {
            return search(key, leaf->left);
        }
        else
        {
            return search(key, leaf->right);
        }
    }
    else
    {
        return false;
    }
}

template <class BT>
bool BinaryTree<BT>::search(BT key)
{
    return search(key, root);
}

template <class BT>
void BinaryTree<BT>::destroyTree(Node<BT> *leaf)
{
    if (leaf != NULL)
    {
        destroyTree(leaf->right);
        destroyTree(leaf->left);
        delete leaf;
    }
}

template <class BT>
void BinaryTree<BT>::destroyTree()
{
    destroyTree(root);
}

template <class BT>
void BinaryTree<BT>::inorderPrint(Node<BT> *leaf)
{
    if (leaf != NULL)
    {
        inorderPrint(leaf->left);
        cout << leaf->value << "   ";
        inorderPrint(leaf->right);
    }
}

template <class BT>
void BinaryTree<BT>::inorderPrint()
{
    inorderPrint(root);
    cout << endl;
}

template <class BT>
void BinaryTree<BT>::postorderPrint(Node<BT> *leaf)
{
    if (leaf != NULL)
    {
        postorderPrint(leaf->left);
        postorderPrint(leaf->right);
        cout << leaf->value << "  ";
    }
}

template <class BT>
void BinaryTree<BT>::postorderPrint()
{
    postorderPrint(root);
    cout << endl;
}

template <class BT>
void BinaryTree<BT>::preorderPrint()
{
    preorderPrint(root);
    cout << endl;
}

template <class BT>
void BinaryTree<BT>::preorderPrint(Node<BT> *leaf)
{
    if (leaf != NULL)
    {
        cout << leaf->value << "  ";
        preorderPrint(leaf->left);
        preorderPrint(leaf->right);
    }
}

int main()
{
    BinaryTree<int> obj;
    obj.insert(10);
    obj.insert(11);
    obj.insert(1);
    obj.insert(130);
    obj.insert(101);
    obj.inorderPrint();
    obj.postorderPrint();
    obj.preorderPrint();
    if(obj.search(130))
    {
        cout<<"Found !"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    
    return 0;
}