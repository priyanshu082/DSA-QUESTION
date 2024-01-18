#include<iostream>
#include<stack>

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

//brute force solution
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        
       if(cnt==1 || cnt==0) return true;
        stack<int> stk;
        temp=head;
        for(int i=0;i<cnt/2;i++){
            stk.push(temp->val);
            temp=temp->next;
        }

        if(cnt%2!=0) temp=temp->next;
        for(int i=0;i<cnt/2;i++){
           if(stk.top()!=temp->val){
               return false;
           } else {
               temp=temp->next;
               stk.pop();
           }
        }
        return true;
    }

    
    //optimised solution 
     bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==nullptr) return false;
        if(head->next==nullptr) return true;
         stack<int> stk;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            stk.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        } 
        if(fast!=nullptr){
            slow=slow->next;
        }

        while(!stk.empty()){
            if(stk.top()!=slow->val) return false;
            else {
                slow=slow->next;
                stk.pop();
            }
        }
        return true;
    }
};

int main(){

    return 0;
}