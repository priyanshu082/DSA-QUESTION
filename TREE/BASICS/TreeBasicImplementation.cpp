#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node(int value):key(value),left(nullptr),right(nullptr){}
};

class BST{
    private:
    Node* root;
    Node* insert(Node* root,int key){
        if(root==nullptr) return new Node(key);

        else if(key>root->key) root->right=insert(root->right,key);

        else if(key<root->key) root->left=insert(root->left,key);

        return root;
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }
    
    public:
    BST():root(nullptr){}

    void insert(int key){
        root=insert(root,key);
    }

    void inorder() {
        std::cout << "Inorder Traversal: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

};


int main(){

    BST tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(120);
    tree.insert(1);
    tree.insert(150);
    tree.insert(104);
    
    tree.inorder();
    return 0;
}