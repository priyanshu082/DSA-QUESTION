#include<iostream>

using namespace std;

int findKRotation(vector<int> &nums){
    // Write your code here.
        int low=0;
        int high =nums.size()-1;
        int mini=INT64_MAX;
        int index=-1;
       while(low<=high){
        int mid =(low+high)/2;

        if(nums[low]<=nums[high]){
          if(nums[low]<mini){
            mini=nums[low];
            index=low;
          }
          break;
        }
         if(nums[low]<=nums[mid]){
            low=mid+1;
           if(nums[low]<mini){
            index=low;
             mini=nums[low];
           }
        }
       
        //right one sorted
         else {
          high = mid - 1;
          if (nums[mid] < mini) {
            index = mid;
            mini = nums[mid];
          }
        }
       }

       return index;    
}

int main(){

    return 0;
}