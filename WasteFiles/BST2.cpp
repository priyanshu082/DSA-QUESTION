#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};


Node* search(Node* root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->val == data)
        return root;
    Node* left = search(root->left, data);
    if (left != NULL)
        return left;
    return search(root->right, data);
}

void insert(Node* root, int par, int data)
{
    // int par;
    Node* parent = search(root, par);
    if (parent == NULL)
        cout << "Parent Not found\n";

    else if (!parent->left)
        parent->left = new Node(data);
    else if (!parent->right)
        parent->right = new Node(data);

    else
    {
        cout << "Parent has both child." << endl;
    }
}

Node* leafNode(Node* root)
{
    Node* curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* deletion(Node* root, int data, bool &del)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val != data)
    {
        root->left = deletion(root->left, data, del);
    }
    if (!del && (root->val != data))
    {
        root->right = deletion(root->right, data, del);
    }
    else if (!del && (root->val == data))
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            del = 1;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            del = 1;
            return temp;
        }

        Node* temp = leafNode(root->right);
        root->val = temp->val;
        root->right = deletion(root->right, temp->val, del);
    }
    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main()
{
    bool flag = 0;
    int r;
    // cout<<"enter the value of root node";
    cout << "Please enter the value of the root node:";
    cin >> r;
    Node *root = new Node(r);

    while (true)
    {
        int choice;
        cout << "\nEnter the corresponding number of the operation you want to perform:" << endl;
        cout << "1--Create a node\n2--Delete an element\n3--Search an element\n4--Display binary tree\n" << endl;
        cout << "Enter 0 to exit the program.\n" << endl;
        cout << "-->";
        cin >> choice;
        if (choice == 1)
        {
            int parent, child;
            cout << "Enter the value of parent node: ";
            cin >> parent;
            cout << "Enter the value of node to be inserted : ";
            cin >> child;
            insert(root, parent, child);
            cout << "\n";
            cout << "The binary tree is: " << endl;
            inorder(root);
            cout << "\n\n";
        }
        else if (choice == 2)
        {
            int i;
            cout << "Enter the value of node to be deleted : ";
            cin >> i;
            Node* newroot = deletion(root, i, flag);
            cout << "\nTraversal order after deletion:" << endl;
            inorder(newroot);
            cout << "\n\n";
            // deletion(index);
        }

        else if (choice == 3)
        {
            int element;
            cout << "Enter the element you want to search: ";
            cin >> element;
            Node* parent = search(root, element);
            if (parent == NULL)
            {
                cout << "\n\nNode not found.\n\n";
            }
            else
            {
                cout << "Node found" << parent->val;
                if (parent->left == NULL)
                {
                    cout << "\n No left child\n";
                }
                else
                {
                    cout << "\nLeft child is :" << parent->left->val << "\n";
                }
                if (parent->right == NULL)
                {
                    cout << "\n No right child\n";
                }
                else
                {
                    cout << "\nRight child is : " << parent->right->val << "\n";
                }
            }
        }
        else if(choice == 4)
        {
            cout << "The binary tree's inorder traversal:" << endl;
            inorder(root);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
    }
    return 0;
}