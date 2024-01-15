#include<iostream>

using namespace std;

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//          if(!head  || !head->next) return head;

//          vector<int> data;

//          ListNode* temp=head;
       
//          while(temp!=nullptr){
//              data.push_back(temp->val);
//              temp=temp->next;
//          }

//          temp=head;
//          int cnt=data.size();
//          for(int i=0;i<cnt;i++){
//              temp->val=data[cnt-i-1];
//              temp=temp->next;
//          }

//          return head;
//     }

//less space 
//  ListNode* reverseList(ListNode* head) {
        
//          ListNode* temp=head;
//          ListNode* prev=nullptr;
//          ListNode* front=nullptr;
//          while(temp!=nullptr){
//            ListNode*  front=temp->next;
//              temp->next=prev;
//              prev=temp;
//              temp=front;
//          }
//          return prev;
//     }
// };

int main(){

    return 0;
}