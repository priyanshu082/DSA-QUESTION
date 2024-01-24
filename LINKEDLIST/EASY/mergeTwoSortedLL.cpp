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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode * newList =new ListNode(0);
        ListNode * temp=newList;
        while(list1 && list2){
            int data1=list1->val;
            int data2=list2->val;
            if(data1>data2){
                
                newList->next=list2;
                newList=list2;
                list2=list2->next;
            } else{
                
                newList->next=list1;
                newList=list1;
                list1=list1->next;
            } 
        }

        while(list1){
                newList->next=list1;
                newList=list1;
                list1=list1->next;
        }
        while(list2){
                
                newList->next=list2;
                newList=list2;
                list2=list2->next;
        }

        return temp->next;
    }
};

int main(){

    return 0;
}