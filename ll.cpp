#include<iostream>

using namespace std;

struct Node{
    int data;
    Node * next;
};



int main(){

    Node *head=new Node;
    head->data=5;
    head->next=nullptr;

    for(int i=1;i<5;i++){
        Node *newNode=new Node;
        newNode->data=i*2;
        newNode->next=nullptr;

        Node* current=head;

        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newNode;
    }


    Node* current=head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current=current->next;
    }
    return 0;
}