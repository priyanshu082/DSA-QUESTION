#include<iostream>

using namespace std;

//garbage code for finding the result but code is optimized 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans;
        if(n==1) return nums[0];
        int low=0;
        int high=n-1;
       while(low<=high){
       int mid=(low+high)/2;

       if(low==high) {
           ans=nums[low];
           break;
       }

       
       if(mid==0 && nums[mid]!=nums[mid+1]){
           ans=nums[mid];
           break;
       }  
       else if(mid==n-1 && nums[mid-1]!=nums[mid]){
           ans=nums[mid];
           break;
       } 
       else if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]){
ans=nums[mid];
break;
       } 
       if(nums[mid-1]==nums[mid]) {
            mid--;
            int p=high-mid;
            if(p%2==0) low=mid+2;
            else high=mid-1;
       }
       else if(nums[mid+1]==nums[mid]){
            mid++;
            int q=high-mid;
            if(q%2==0) high=mid-2;
            else low=mid;
       } 
      
          
       }
       return ans;
    }
};

//another approach and better short code
int singleNonDuplicate(vector<int>& nums)
{	
	int n=nums.size();
	if(n==1) return nums[0];
	int low=1;
	int high=n-2;
	int ans;

	if(nums[0]!=nums[1]) {
			 return nums[0];
	
		} 
		if(nums[n-2]!=nums[n-1]){
			return nums[n-1];

		}


	while(low<=high){

		
		// if(left==high) {
		// 	ans=nums[low];
		// 	break;
		// }
		int mid=(low+high)/2;
		
		
		if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) {
			ans=nums[mid];
			break;
		}

    if ((mid % 2 == 1 && nums[mid]==nums[mid-1]) ||
                    (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
                }
                else high=mid-1;
		
		
	}
	return ans;
}


int main(){

    return 0;
}