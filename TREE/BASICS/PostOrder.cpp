#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node* right;

    Node(int value):data(value),left(nullptr),right(nullptr){}
};

class BT{
    private:
    Node* root;
    Node* insert(Node* root,int key){

        if(root==nullptr){
            return new Node(key);
        }

        if(key<root->data){
            root->left=insert(root->left,key);
        }
        else if(key>root->data){
            root->right=insert(root->right,key);
        }

        return root;
    }


    void PostOrder(Node * root){
        if(root==nullptr) return ;

     PostOrder(root->left);
     PostOrder(root->right);
     cout<<root->data<<" ";
    }

    public:
    BT():root(nullptr){}

    void insert(int key){
        root=insert(root ,key);
    }

    void PostOrder(){
        PostOrder(root);
    }

    


};


int main(){
   BT tree;
    tree.insert(6);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(5);
    tree.insert(1);
    tree.insert(10);
    tree.insert(8);
    tree.insert(7);
    
    tree.PostOrder();
}