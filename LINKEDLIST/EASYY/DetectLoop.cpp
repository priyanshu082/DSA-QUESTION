#include<iostream>
#include<unordered_set>

using namespace std;

 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:

//brute forcee approach
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head!=NULL){
            if(set.find(head)!=set.end()) return true;
            set.insert(head);
            head=head->next;
        }
        return false;
    }
     
            //fast appraoch with fast slow
     bool hasCycle2(ListNode *head) {
        ListNode* slow =head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
      
        return false;
    }
};

int main(){

    return 0;
}