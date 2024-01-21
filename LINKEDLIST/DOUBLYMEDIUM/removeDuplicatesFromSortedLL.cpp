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
          this -> data = data;
          this -> prev = prev;
          this -> next = next;
      }
 };


Node * removeDuplicates(Node *head)
{
    if(!head || !head->next) return head;
    Node * temp=head;
    int num=temp->data;
    int cnt=0;
    temp=temp->next;
    while(temp){
        if(temp->data==num){
            temp->prev->next=temp->next;
            if(temp->next)temp->next->prev=temp->prev;
            else break;
            Node * nxt= temp->next;
            delete temp;
            temp=nxt;
        } else {
            if(temp->next)temp=temp->next;
             else break;
            num=temp->prev->data; 
        }
    }
    return head;
}


int main(){

    return 0;
}