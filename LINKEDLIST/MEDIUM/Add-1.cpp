#include<iostream>

using namespace std;


class Node {
 public:
      int data;
      Node *next;
      Node() {
          this->data = 0;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->next = NULL;
      }
      Node (int data, Node *next) {
          this->data = data;
          this->next = next;
      }
 };
 

Node *addOne(Node *head)
{
    Node * temp=head;
    Node * prev=NULL;
    while(temp){
        Node * nxt= temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }

    int carry=0;
    Node * prev2=NULL;
    prev->data+=1;

        while(prev){
            Node * nxt = prev->next;
            prev->next=prev2;
            prev->data+=carry;

            if(prev->data==10){
                carry=1;
                prev->data=0;
            } else carry=0;

            prev2=prev;
            prev=nxt;
        }

        if(carry==1){
            Node * newHead=new Node(1);
            newHead->next=head;
            head=newHead;
        }
        
    return head;
}

//fast nd clean solution 
int helper(Node* head){
    if(!head) return 1;

    int carry=helper(head->next);
    head->data+= carry;
    if(head->data==10){
        head->data=0;
        return 1;
    } else {
        return 0;
    }
}
Node *addOne(Node *head)
{
    Node * temp=head;
   int carry=helper(head);

   if(carry==1){
Node * newHead=new Node (1);
newHead->next=head;
head=newHead;
   }

   return head;
}


int main(){

    return 0;
}