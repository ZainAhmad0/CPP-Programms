#include <iostream>
#include <queue> // for level order traversal through queues

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
    void levelOrderPrint(Node<BT> *leaf);
    int sizeOfTreeThroughLevelOrderTraversal(Node<BT> *leaf);
    BT findMax(Node<BT> *leaf);
    BT findMin(Node<BT> *leaf);
    int sizeOfBinaryTree(Node<BT> *leaf);

public:
    BinaryTree();
    ~BinaryTree();
    void insert(BT key);
    bool search(BT key);
    bool isEmpty();
    void destroyTree();
    void inorderPrint();
    void postorderPrint();
    void preorderPrint();
    void levelOrderPrint();
    BT findMax();
    BT findMin();
    int sizeOfBinaryTree();
    int sizeOfTreeThroughLevelOrderTraversal();
};

template <class BT>
int BinaryTree<BT>::sizeOfTreeThroughLevelOrderTraversal(Node<BT> *leaf)
{
    int count = 0;
    Node<BT> *temp;
    queue<Node<BT> *> objQueue;
    if (leaf == NULL)
        return 0;
    objQueue.push(leaf);
    while (!objQueue.empty())
    {
        temp = objQueue.front();
        count++;
        objQueue.pop();
        if (temp->left != NULL)
            objQueue.push(temp->left);
        if (temp->right != NULL)
            objQueue.push(temp->right);
    }
    return count;
}

template <class BT>
int BinaryTree<BT>::sizeOfTreeThroughLevelOrderTraversal()
{
    return sizeOfTreeThroughLevelOrderTraversal(root);
}

template <class BT>
int BinaryTree<BT>::sizeOfBinaryTree()
{
    return sizeOfBinaryTree(root);
}

template <class BT>
int BinaryTree<BT>::sizeOfBinaryTree(Node<BT> *leaf)
{
    if (leaf == NULL)
    {
        return 0;
    }
    return (sizeOfBinaryTree(leaf->left) + 1 + sizeOfBinaryTree(leaf->right));
    // + 1 is for root node
}

template <class BT>
BT BinaryTree<BT>::findMax()
{
    return findMax(root);
}

template <class BT>
BT BinaryTree<BT>::findMax(Node<BT> *leaf)
{
    if (leaf->right == NULL)
    {
        return leaf->value;
    }
    return findMax(leaf->right);
}

template <class BT>
BT BinaryTree<BT>::findMin()
{
    return findMin(root);
}

template <class BT>
BT BinaryTree<BT>::findMin(Node<BT> *leaf)
{
    if (leaf->left == NULL)
    {
        return leaf->value;
    }
    return findMin(leaf->left);
}

template <class BT>
bool BinaryTree<BT>::isEmpty()
{
    return (root == NULL);
}

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
    else // for the first time when there is no root so this else would be executed that time
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

template <class BT>
void BinaryTree<BT>::levelOrderPrint(Node<BT> *leaf)
{
    Node<BT> *temp;
    queue<Node<BT> *> objQueue;
    if (leaf == NULL)
        return;
    objQueue.push(leaf);
    while (!objQueue.empty())
    {
        temp = objQueue.front();
        objQueue.pop();
        cout << temp->value << " ";
        if (temp->left != NULL)
            objQueue.push(temp->left);
        if (temp->right != NULL)
            objQueue.push(temp->right);
    }
}

template <class BT>
void BinaryTree<BT>::levelOrderPrint()
{
    levelOrderPrint(root);
}

int main()
{
    BinaryTree<int> obj;
    obj.insert(10);
    obj.insert(1122);
    obj.insert(1);
    obj.insert(130);
    obj.insert(101);
    obj.insert(0);
    obj.insert(-234);
    // cout<<"Size of Tree (level order traversal) is : "<<obj.sizeOfTreeThroughLevelOrderTraversal()<<endl;
    // cout<<"Size of Tree is : "<<obj.sizeOfBinaryTree()<<endl;
    // cout<<"Min is : "<<obj.findMin()<<endl;
    // cout<<"Max is : "<<obj.findMax()<<endl;
    // cout << "Inorder Traversal : ";
    // obj.inorderPrint();
    // cout << "Postorder Traversal : ";
    // obj.postorderPrint();
    // cout << "Preorder Traversal : ";
    // obj.preorderPrint();
    // cout << "Level Order Traversal : ";
    // obj.levelOrderPrint();
    // cout<<endl;
    // if(obj.search(130))
    // {
    //     cout<<"Found !"<<endl;
    // }
    // else
    // {
    //     cout<<"Not Found"<<endl;
    // }

    return 0;
}