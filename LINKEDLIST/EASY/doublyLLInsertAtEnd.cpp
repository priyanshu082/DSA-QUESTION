#include<iostream>

using namespace std;

 struct Node {
      int value;
      Node *prev;
      Node *next;
      Node() : value(0), prev(nullptr), next(nullptr) {}
      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 };


Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(!head){
        Node * last=new Node(k);
        head=last;
        return head;
    } else if(!head->next){
         Node * last=new Node(k);
         head->next=last;
         last->prev=head;
         return head;
    } else{

    Node * current=head;
     
     while(current->next->next!=nullptr){
        current = current->next;
     }
        Node* last=new Node(k);
     current->next->next=last;
     last->prev=current->next;

     return head;
    }
}

int main(){

    return 0;
}
