#include<iostream>

using namespace std;

//binary search appraoch 
 int search(vector<int>& nums, int n, int target)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low=0;
        int high =nums.size()-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid ;
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]) high=mid-1;
            else low=mid+1;
        }
        else {
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            } else high=mid-1; 
        }
            
        }
        return -1;
}

int main(){

    return 0;
}