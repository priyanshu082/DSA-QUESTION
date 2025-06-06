#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Stack{
    Node* top;

    public:
    Stack(){
        top=NULL; 
    }

    void push(int data){
        Node* newNode= new Node(data);
        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }
     
    void top(){
        if(top==NULL){
            cout<<"Stack is Empty"<<endl;
            return ;
        }
        cout<<top->data<<endl;
    }

    void size(){
        int count=0;
        Node* temp=top;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        cout<<"Size is : "<< count<<endl;
    }

    void isEmpty(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Stack is not empty"<<endl;
        }
    }
};

int main(){
    return 0;

}