#include <iostream>
#include<set>
#include<unordered_set>

using namespace std;

//brute force solution   o(n@2)
class Solution {
public:
 bool ls(vector<int>& nums,int n){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==n){
                    return true;
                }
            }
            return false;
        }
    int longestConsecutive(vector<int>& nums) {
        //brute force solution
          int maxi=0;
        for(int i=0;i<nums.size();i++){
            int k=nums[i];
            int counter=1;
          
            while(ls(nums,k+1)==true){
                k=k+1;
                counter++;
            }
            maxi=max(maxi,counter);
        }
        return maxi;
    }
};

//better approach 1   here i have used set which take TC=o(nlogn) ND SC=O(N).
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }

        int LastMin=INT_MIN;
         int maxi=0;
        int counter=0;
        for(auto it:set){
            if(it>LastMin+1){
               counter=1;
               LastMin=it;
            } else if(it==LastMin+1){
              counter++;
              LastMin=it;
            }
          maxi=max(maxi,counter);
        }
        return maxi;
    }
};

//better appraoch 2 .....tc=o(n) sc=o(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }

        int LastMin=INT_MIN;
         int maxi=0;
        int counter=0;
        for(auto it:set){
            if(set.find(it-1)==set.end()){
               counter=1;
               LastMin=it;
               while(set.find(LastMin+1)!=set.end()){
                   LastMin++;
                   counter++;
               }
            } 
          maxi=max(maxi,counter);
        }
        return maxi;
    }
};

//most optimal approach .... tc(nlogn) sc(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());

        int LastMin=INT_MIN;
         int maxi=0;
        int counter=0;
      for(int i=0;i<nums.size();i++){
             if(nums[i]>LastMin+1){
                 counter=1;
                 LastMin=nums[i];
             } else if(nums[i]==LastMin+1){
                 counter++;
                 LastMin=nums[i];
             }
         maxi=max(maxi,counter);
      }
        return maxi;
    }
};



int main(){


    return 0;
}