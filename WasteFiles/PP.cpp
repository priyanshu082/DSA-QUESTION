#include<iostream>

using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

class BinaryTree{
    public:
    TreeNode * pp;

   
    BinaryTree()
    {
        pp=nullptr;
    }
     
    void insert(int value)
    {
        pp=insertRecursive(pp,value);
    }

    TreeNode* insertRecursive(TreeNode *current ,int value)
    {
        if(current==nullptr){
            return new TreeNode(value);
        } else if(value<current->data){
            current->left=insertRecursive(current->left,value);
        } else if(value>current->data){
            current->right=insertRecursive(current->right,value);
        }
        return current;
    }

    void inOrderTransversal(TreeNode* current){
        if(pp==nullptr) cout<<"No elements in tree"<<endl;
        if(current!=nullptr){
            inOrderTransversal(current->left);

            cout<<current->data<<"->";

            inOrderTransversal(current->right);
        }
    }

    void deletenode(int value){
        pp=deleteRecursive(pp,value);
    }

    TreeNode* deleteRecursive(TreeNode* current,int value){
        
    }

};



int main(){

    BinaryTree myTree;

    // myTree.insert(50);
    // myTree.insert(30);
    // myTree.insert(20);
    // myTree.insert(40);
    // myTree.insert(70);
    // myTree.insert(60);
    // myTree.insert(80);
    // myTree.insert(10);

    int y;
    do{
    cout<<"Enter the operation you want to perform"<<endl;
    cout<<"1.Insertion"<<endl;
    cout<<"2.Transversal"<<endl;
    cout<<"3.Exit"<<endl;

    cin>>y;
    switch (y)
    {
    case 1:
    int value;
    cout<<"Enter the value to enter in Tree"<<endl;
    cin>>value;
    myTree.insert(value);
    break;

    case 2:
    myTree.inOrderTransversal(myTree.pp);
    cout<<endl; 
    break;

    case 3:
    cout<<"Program ends"<<endl;
    
    default:
    cout<<"Please enter the valid value"<<endl;
        break;
    }
    } while(y!=3);

   

    return 0;
}