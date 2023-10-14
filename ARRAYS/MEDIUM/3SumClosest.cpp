#include<iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
         int closest=INT_MAX;
         int mini=INT_MAX;
         for(int i=0;i<nums.size()-2;i++){
             int left=i+1;
             int right=nums.size()-1;
             while(left<right){
                 int sum=nums[i]+nums[left]+nums[right];
                 int diff=sum-target;
                 int flag=0;
                 if(diff<0) {
                 diff=diff*-1;
                    flag=1;
                 }
                 if(diff<mini){
                     mini=diff;
                     closest=sum;
                 }
                 if(flag==1) diff=diff*-1;
                 if(diff<0) left++;
                 else right--;
             }
         }
        return closest;
    }

int main(){
    return 0;
}