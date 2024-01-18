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

//most worst appraoch anybody can think of 
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * temp=head;
        vector<int> vec;
        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        sort(vec.begin(),vec.end());
        int len=vec.size();
        temp=head;
        for(int i=0;i<len;i++){
            temp->val=vec[i];
            temp=temp->next;
        }
        return head;
    }

    
};

//optimised solution
class Solution2 {
public:

    ListNode *findMid(ListNode * head){
        ListNode * slow=head;
        ListNode * fast=head,*prev;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!fast){
            slow=prev;
        }

        return slow;
    }

   ListNode* sorting(ListNode* list1 ,ListNode* list2){
       ListNode * dummy=new ListNode(0);
       ListNode * temp=dummy;
       while(list1 && list2){
           if(list1->val > list2->val){
               temp->next=list2;
               list2=list2->next;
           } else{
               temp->next=list1;
               list1=list1->next;
           }
           temp=temp->next;
       }

      temp->next= list1? list1: list2;

       return dummy->next;
    }

   ListNode* merge_sort(ListNode *head ){
       if(head==NULL || head->next==NULL) return head;
       ListNode * mid=findMid(head);
       ListNode * leftHead=head, *rightHead=mid->next;
       mid->next=NULL;
       leftHead=merge_sort(leftHead);
       rightHead=merge_sort(rightHead);
        return sorting(leftHead,rightHead);
    }

    ListNode* sortList(ListNode* head) {
         if(head==NULL || head->next==NULL) return head;
       head=merge_sort(head);
       return head;
    }
};

int main(){

    return 0;
}