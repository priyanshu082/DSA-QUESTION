#include<iostream>

using namespace std;

class node{
    public:
    int key;
    node*left;
    node*right;

    node(int val):key(val),right(nullptr),left(nullptr){}
};

class BST{
private:
node *root;

node *insert(node*root,int key){
    if(root==nullptr)
    return new node(key);

    else if(key > root->key)
     root->right=insert(root->right,key);

    else if(key<root->key)
    root->left=insert(root->left,key) ;
}

node *deleteNode(node * root ,int key){
    if(root==NULL)
    return NULL;

    if(root->key==key)
    return helper(root);

    node* dummy=root;

    while(root!=NULL){
        if(root->key>key){
             if(root->left!=NULL && root->left->key==key){
             root->left=helper(root->left);
             break;
             }
             else root=root->left;
        } else if(root->key<key){
            if(root->right!=NULL && root->right->key==key){
                root->right=helper(root->right);
                break;
            } else root=root->right;
        }
    }
    return dummy;
}

node* helper(node* root){
    if(root->left==NULL) return root->right;
    else if(root->right==NULL) return root->left;

    node* rightChild=root->right;
    node* lastRight=findLastRight(root->left); //find last right of root->left
    lastRight->right=rightChild;

    return root->left;

}
node* findLastRight(node* root){
    if(root==NULL || root->right==NULL)
    return root;

    return findLastRight(root->right);
}


public:
BST():root(nullptr){};

void insert(int key){
    root=insert(root,key);
}

node* Nodedelete(int key){
    return deleteNode(root,key);
}

};

int main(){

    return 0;
}