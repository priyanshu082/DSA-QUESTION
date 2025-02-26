#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL; 
        }
};


//root left right
void preorder(Node* node){
    if(node==nullptr){
        return ;
    }
    cout<<node->data;
    preorder(node->left);
    preorder(node->right);

}

void postorder(Node* node){
    //left right root
    if(node==nullptr){
        return ;
        }
        postorder(node->left);
        postorder(node->right);
        cout<<node->data;
}

void inorder(Node* node){
    //left root right
    
    if(node==nullptr){
        return ;
        }
        postorder(node->left);
        cout<<node->data;
        postorder(node->right);
}




int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    

    return 0;
}

