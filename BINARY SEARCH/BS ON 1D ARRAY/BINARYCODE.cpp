#include<iostream>

using namespace std;

//iterative binary search code
 int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }

//binary search through recursion
int binary(vector<int>& nums,int low ,int high ,int target){
    if(low>high) return -1;
   int mid=(low +high)/2;
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) {
      return binary(nums,mid+1,high,target);
    }
    else {
        return binary(nums,low,mid-1,target);
    }
 
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(nums,0,n-1,target);
    }

int main(){

    return 0;
}