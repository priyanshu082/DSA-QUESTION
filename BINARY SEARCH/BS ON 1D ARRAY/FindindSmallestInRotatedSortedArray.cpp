#include <iostream>

using namespace std;


//finding the smallest number in rotated and sorted array using binary search
 int findMin(vector<int>& nums) {
        int low=0;
        int high =nums.size()-1;
        int mini=INT_MAX;
       while(low<=high){

        int mid =(low+high)/2;
        //right one sorted
        if(nums[mid]<=nums[high]){
            mini=min(mini,nums[mid]);
            high=mid-1;
        } 

        //left one sorted
        if(nums[low]<=nums[mid]){
            mini=min(mini,nums[low]);
            low=mid+1;
        }
       }
       return mini;
    }



int main(){

    return 0;
}