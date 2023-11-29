/* Program to implement Binary Search Tree in c++ using classes and objects  */


#include <iostream>
#include <cstdlib>

using namespace std;


class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    Node* createNode(int);
    Node* insertNode(Node*, int);
    Node* deleteNode(Node*, int);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    Node* findMinimum(Node*);

    /* accessor function helps to get the root node in main function
    because root is private data member, direct access is not possible */
    Node* getRoot()
    {
        return root;
    }

    /* mutator method helps to update root ptr after insertion cause
    root is not directly updatable in the main function because it's a private data member */
    void setRoot(Node* ptr)
    {
        root = ptr;
    }
};

/* Helper function to create a new node in each function call of insertNode */
Node* BinaryTree ::createNode(int n)
{
    Node* newNode = new Node(n);
    return newNode;
}

/* Helps to get inorder predessor to delete the node from tree */
Node* BinaryTree ::findMinimum(Node* rootPtr)
{
    while (rootPtr->left != nullptr)
    {
        rootPtr = rootPtr->left;
    }
    return rootPtr;
}


Node* BinaryTree ::insertNode(Node* rootPtr, int n)
{
    if (rootPtr == nullptr)
    {
        return createNode(n);
    }
    if (n < rootPtr->data)
    {
        rootPtr->left = insertNode(rootPtr->left, n);
    }
    if (n > rootPtr->data)
    {
        rootPtr->right = insertNode(rootPtr->right, n);
    }
    return rootPtr;
}


Node* BinaryTree ::deleteNode(Node* rootPtr, int n)
{
    if (rootPtr == nullptr)
    {
        cout << "Node to be deleted is not present.!" << endl;
        return rootPtr;
    }
    else if (n < rootPtr->data)
    {
        rootPtr->left = deleteNode(rootPtr->left, n);
    }
    else if (n > rootPtr->data)
    {
        rootPtr->right = deleteNode(rootPtr->right, n);
    }
    else
    {
        if (rootPtr->left == nullptr && rootPtr->right == nullptr)
        {
            delete rootPtr;
            rootPtr = nullptr;
        }
        else if (root->left == nullptr)
        {
            struct Node* temp = rootPtr;
            rootPtr = rootPtr->right;
            delete temp;
        }
        else if (rootPtr->right == nullptr)
        {
            struct Node* temp = rootPtr;
            rootPtr = rootPtr->left;
            delete temp;
        }
        else
        {
            Node* temp = findMinimum(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->left = deleteNode(rootPtr->right, temp->data);
        }
    }

    return rootPtr;
}


void BinaryTree ::inOrder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}

void BinaryTree ::preOrder(Node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << "\t";
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree ::postOrder(Node* root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
}

int main()
{
    BinaryTree bin;
    int ch, ele, res;
    Node* ptr;
    do
    {
        cout << "1 - Insert Node\n";
        cout << "2 - IN-ORDER Traversal\n";
        cout << "3 - PRE-ORDER Traversal\n";
        cout << "4 - POST-ORDER Traversal\n";
        cout << "Enter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element to insert:";
            cin >> ele;
            /* calling insertNode function by passing root ptr to the function,
               root ptr can be obtained by accessor function getRoot() */
            ptr = bin.insertNode(bin.getRoot(), ele);
            /* updating the root ptr*/
            bin.setRoot(ptr);
            break;
        case 2:
            cout << "---IN-ORDER TRAVERSAL---" << endl;
            bin.inOrder(bin.getRoot());
            cout << endl;
            break;
        case 3:
            cout << "---PRE-ORDER TRAVERSAL---" << endl;
            bin.preOrder(bin.getRoot());
            cout << endl;
            break;
        case 4:
            cout << "---POST-ORDER TRAVERSAL---" << endl;
            bin.postOrder(bin.getRoot());
            cout << endl;
            break;
        case 5:
            cout << "Enter node to be deleted:";
            cin >> ele;
            ptr = bin.deleteNode(bin.getRoot(), ele);
            bin.setRoot(ptr);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch >= 1 && ch <= 5);

    return 0;
}