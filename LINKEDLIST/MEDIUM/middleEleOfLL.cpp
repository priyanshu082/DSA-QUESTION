#include<iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

 int lengthOfNode(ListNode* head){
        if(!head) return 0;
        int cnt=1;
        while(head->next!=nullptr){
            cnt++;
            head=head->next;
        }
        return cnt;
    }

    //slow appraoch brute force appraoch
    ListNode* middleNode(ListNode* head) {
        int len=lengthOfNode(head);
        if(len/2!=0) len=(len/2)+1;
        else len=len/2;
        for(int i=0;i<len-1;i++){
            head=head->next;
        }
        return head;
    }

    //fast approach 
     ListNode* middleNode1(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main(){

    return 0;
}