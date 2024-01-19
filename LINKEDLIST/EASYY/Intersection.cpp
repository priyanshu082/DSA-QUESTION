#include<iostream>
#include<map>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//naieve solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      map<ListNode*,int> mpp;
      ListNode *tempA=headA;
      ListNode *tempB=headB;
      while(tempA){
          mpp[tempA]=1;
          tempA=tempA->next;
      }

      while(tempB){
          if(mpp.find(tempB)!=mpp.end()) return tempB;
          else tempB=tempB->next;
      }

      return NULL;
    }
};

//optimal appraoch with o(n1 + 2n2)
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

      if(!headA && !headB) return NULL;
      if(headA==headB) return headA;
      ListNode *tempA=headA;
      ListNode *tempB=headB;
      int cntA=1;
      int cntB=1;
      while(tempA && tempA->next && tempB && tempB->next){
          tempA=tempA->next->next;
          tempB=tempB->next->next;
          cntA+=2;
          cntB+=2;
      }

      while(tempA && tempA->next){
          tempA=tempA->next->next;
          cntA+=2;
      }

      while(tempB && tempB->next){
           tempB=tempB->next->next;
           cntB+=2;
      }

      if(!tempA) cntA--;
      if(!tempB) cntB--;

      if(cntA>cntB){
          for(int i=0;i<cntA-cntB;i++){
              headA=headA->next;
          }  
      } else if(cntA<cntB){
         for(int i=0;i<cntB-cntA;i++){
              headB=headB->next;
          } 
      } 
      
      while(headA && headB && headA!=headB){
      
          headA=headA->next;
          headB=headB->next;

          if(headA==headB) return headA;
      }

      return (headA==headB) ? headA : NULL;
    }
};

//most optimal appraoch O(n1+n2)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(!headA || !headB) return NULL;
        if(headA==headB) return headA;
        ListNode * tempA=headA;
        ListNode * tempB=headB;

        while(!(!tempA && !tempB) && tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;

            if(tempA==tempB) return tempA;

            if(tempA==NULL) tempA=headB;
            if(tempB==NULL) tempB=headA;
        }

        return tempA;
    }
};
int main(){
    return 0;
}