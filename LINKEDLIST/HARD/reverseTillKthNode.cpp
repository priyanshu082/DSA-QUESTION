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

    ListNode * findKthNode(ListNode * kthNode,int k){
        int cnt=1;
        while(cnt!=k){
            if(kthNode){
                kthNode=kthNode->next;
                cnt++;
            }
            else return NULL;
        }
        return kthNode;
    }

    void reverse(ListNode * head){
        ListNode * temp=head;
        ListNode * prev=NULL;

        while(temp){
            ListNode * nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode * temp=head;
        ListNode * kthNode=head;
        ListNode * prev=NULL;
        ListNode * nxtNode=NULL;
        while(temp){
            kthNode=findKthNode(kthNode,k);

            if(!kthNode) break;
            else {
               nxtNode=kthNode->next;
               kthNode->next=NULL;
            }


            reverse(temp);

            if(temp==head) {
                head=kthNode;
                prev=temp;
                
                kthNode=nxtNode;
                prev->next=kthNode;
                temp=nxtNode;

            } else{
                prev->next=kthNode;
                kthNode=nxtNode;
                prev=temp;
                temp=nxtNode;
            } 

        }
       prev->next=temp;
        return head;
    }
};


int main(){

    return 0;
}