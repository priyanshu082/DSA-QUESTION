#include<iostream>

using namespace std;

class Node{
public:
int data;
Node * next;
Node * prev;
Node(int val):data(val),next(nullptr),prev(nullptr){}
};

Node* reverseDLL(Node* head)
{   
    // Write your code here
    Node * current =head;
    Node * temp=nullptr;


   while(current){
       temp=current->prev;
       current->prev=current->next;
       current->next=temp;
       current=current->prev;
   }

    if(temp) head=temp->prev;
   return head;

}


int main(){

    return 0;
}