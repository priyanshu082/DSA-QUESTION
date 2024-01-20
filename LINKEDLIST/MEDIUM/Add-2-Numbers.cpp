#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//space O(1) time complexity=Omax(m,n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * t1=l1;
        ListNode * t2=l2;
        int carry=0;
        bool flag=true;
        ListNode * prev1=NULL;
        ListNode * prev2=NULL;
        while(t1 && t2){
            int temp=t1->val;
            t1->val=t1->val+t2->val+carry;
            t2->val=t1->val;
            if(t1->val>=10){
                carry=t1->val/10;
                t1->val=t1->val%10;
                t2->val=t1->val%10;
            } else carry=0;

            prev1=t1;
            prev2=t2;
            t1=t1->next;
            t2=t2->next;
        }

        

        while(t1){
            t1->val=t1->val+carry;
            if(t1->val>=10){
                carry=t1->val/10;
                t1->val=t1->val%10;
            } else carry=0;
            prev1=t1;
            t1=t1->next;
        
        }

        while(t2){
            flag=false;
            t2->val=t2->val+carry;
            if(t2->val>=10){
                carry=t2->val/10;
                t2->val=t2->val%10;
            } else carry=0;
            prev2=t2;
            t2=t2->next;
        }

        if(carry>0){
           ListNode * newHead=new ListNode(carry);
           if(flag) prev1->next=newHead;
           else prev2->next=newHead;
        }
        return flag ? l1 : l2;
    }
};


//most optimal appraoch with clean code
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy=new ListNode(0);
        ListNode * temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int x= l1 ? l1->val : 0;
            int y= l2 ? l2->val : 0;
            int sum=x+y+carry;
            carry=sum/10;
            ListNode * newNum = new ListNode(sum%10);
            temp->next=newNum;
            temp=temp->next;
            l1=l1?l1->next:nullptr;
            l2=l2?l2->next:nullptr;
        }
        return dummy->next;
    }
};

int main(){

    return 0;
}