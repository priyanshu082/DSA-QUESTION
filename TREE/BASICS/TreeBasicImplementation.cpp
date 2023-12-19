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
    
    public:

    BST():root(nullptr){}

    void insert(int key){
        root=insert(root,key);
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
    return 0;
}