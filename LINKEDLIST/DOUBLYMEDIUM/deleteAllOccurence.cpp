#include<iostream>

using namespace std;


 class Node {
 public:
      int data;
      Node *prev;
      Node *next;
      Node() {
          this->data = 0;
          this->prev = NULL;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->prev = NULL;
          this->next = NULL;
      }
      Node (int data, Node *next, Node *prev) {
          this->data = data;
          this->prev = prev;
          this->next = next;
      }
 };


Node * deleteAllOccurrences(Node* head, int k) {
        Node * temp=head;
        
        while(temp){
            if(temp->data==k){
                Node * nxt=temp->next;
                if(temp->next)temp->next->prev=temp->prev;
                
                if(temp->prev){
                    temp->prev->next=temp->next;
                } else {
                    head=temp->next;
                }
                delete temp;
                temp=nxt;
            } else temp=temp->next;
        }
        return head;
}

int mani(){

    return 0;
}