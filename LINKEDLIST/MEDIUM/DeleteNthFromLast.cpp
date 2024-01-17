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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        if(head==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        int len=1;
        int cnt=1;
        while(fast!=NULL && fast->next!=NULL ){
            prev=slow;
            slow=slow->next;
            cnt++;
            fast=fast->next->next;
            len+=2;
        }
        if(fast==NULL) {
            len--;
            cnt--;
            slow=prev;
        }

        int pos=len-n;
        ListNode * temp=head;
        ListNode * prevTemp=NULL;
        if(pos==0) return head->next;
        if(pos>=cnt)
        {
            for(int i=0;i<pos-cnt;i++)
            {
                slow=slow->next;
            }
            if (slow->next == NULL) {
                if (prev != NULL) {
                    prev->next = NULL;
                } else {
                    head = NULL;
                }
    }
            else slow->next=slow->next->next;
        } else{
            for(int i=1;i<pos;i++){
                prev=temp;
                temp=temp->next;
            }
            if(temp->next==NULL){
                if(prev!=NULL) prev->next=NULL;
                else head=NULL;
            }
           else temp->next=temp->next->next;
        }
        return head;
    }
};

int main(){

    return 0;
}