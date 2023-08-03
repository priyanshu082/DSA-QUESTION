#include<iostream>

using namespace std;

//not so optimal appraoch tc=n
int findPeakElement(vector<int>& nums) {
        int ans;
        int n=nums.size();
        if(n==1) return 0;
        if (nums[0]>nums[1]) return 0;
        if(nums[n-2]<nums[n-1]) return n-1;
        for(int i=1;i<n-2;i++){
           if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) {
               ans=i;
               break;
           }
        }
        return ans;
    }

//

int main(){

    return 0;
}