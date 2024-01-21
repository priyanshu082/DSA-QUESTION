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


vector<pair<int, int>> findPairs(Node *head, int k) {
  vector<pair<int, int>> vector;
  if (!head)
    return vector;
  if (!head->next)
    return vector;
  Node *left = head;
  Node *right = head->next;

  while (right && right->next && right->next->next) {
    right = right->next->next;
  }

  if (right->next)
    right = right->next;

  while (left != right && right->next!=left) {
    if (left->data + right->data == k) {
      vector.push_back({left->data, right->data});
      if (left->next)
        left = left->next;
      if (right->prev)
        right = right->prev;
    }

    else if (left->data + right->data > k) 
     right = right->prev;
    
    else 
    left = left->next;
    

 
  }

  return vector;
}


int main(){

    return 0;
}