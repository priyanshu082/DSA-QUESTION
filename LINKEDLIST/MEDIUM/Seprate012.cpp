#include<iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList(Node *head){

    if(!head || !head->next) return head;
    Node * list0=new Node(0),*temp0=list0;
    Node * list1=new Node(0),*temp1=list1;
    Node * list2=new Node(0),*temp2=list2;
    Node * temp=head;
    
    while(temp){

        if(temp->data==0){
            list0->next=new Node(0);
            list0=list0->next;
        } else if(temp->data==1){
           
            list1->next=new Node(1);
            list1=list1->next;
        } else {
          
            list2->next=new Node(2);
            list2=list2->next;
        }
        temp=temp->next;

    }

    list0->next=temp1->next;
    list1->next=temp2->next;
    head=temp0->next;
    return head;
}

int main(){

    return 0;
}
