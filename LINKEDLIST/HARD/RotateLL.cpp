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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next ) return head;
        ListNode * temp=head;
        ListNode * end=head;
        ListNode * prev=NULL;
        int cnt=0;
        int size=1;
        while(cnt<k){
            while(end->next){
                prev=end;
                end=end->next;
                size++;
            }
            if(k>size)k=k%size;
            if(k==0) return head;
            end->next=temp;
            prev->next=NULL;
            temp=end;
            cnt++;
        }
        head=temp;
        return head;
    }
};


class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next ) return head;
         ListNode * temp=head;
        ListNode * end=head;
        ListNode * prev1=head;
        ListNode * prev2=head;
        int cnt=0;
        int size=1;

        while(end->next){
            size++;
            end=end->next;
        }

        k=k%size;
        if(k==0) return head;
  
           
                while(cnt<(size-k)){
                    prev2=prev1;
                    prev1=prev1->next;
                    cnt++;
                }
          
        end->next=temp;   
        prev2->next=NULL;
        head=prev1;

        
        return head;
    }
};
int main(){

    return 0;
}