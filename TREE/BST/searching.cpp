#include <iostream>

using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;

    node(int val) : key(val), right(nullptr), left(nullptr) {}
};

class BST
{
private:
    node *root;
    node *insert(node *root, int key)
    {
        if (root == nullptr)
            return new node(key);

        else if (key > root->key)
            root->right = insert(root->right, key);
        else if (key < root->key)
            root->left = insert(root->left, key);

            return root;
    }

    bool bstSearch(node *root, int key)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (root->key == key)
        {
            return true;
        }
        else if (key < root->key)
        {
           return bstSearch(root->left, key);
        }
        else if (key > root->key)
        {
            return bstSearch(root->right, key);
        }
    }

public:
    BST() : root(nullptr){};
    void insert(int key)
    {
        root = insert(root, key);
    }

    bool search(int key)
    {
        return bstSearch(root, key);
    }
};

int main()
{

    BST tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(120);
    tree.insert(1);
    tree.insert(150);
    tree.insert(104);

    cout<<tree.search(30)<<endl;
    cout<<tree.search(3)<<endl;
    return 0;

    
}