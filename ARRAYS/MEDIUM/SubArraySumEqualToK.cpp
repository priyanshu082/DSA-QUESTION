#include<iostream>

using namespace std;

//brute approach would be running loop inside a for loop

//need to be corrected yet
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int sum=nums[0],counter=0;
        int n=nums.size();

        if(n==1 && k==nums[0]){
           return counter=1;
        } else if(n==1 && k!=nums[0]){
            return counter=0;
        } else{
             while(left<n){
            if(sum<k && left==right){
                sum=sum+nums[left];
                right++;
            } else if(sum<k){
                sum+=nums[right];
                right++;
            } else if(sum==k){
               if(right<=n-1){
                   sum+=nums[right];
                   counter++;
                   right++;
               } else{
                   counter++;
                   sum-=nums[left];
                   return counter;
               }
                
            } else if(sum>k){
                sum-=nums[left];
                left++;
            }
        }
        }
       
        return counter;
    }
};

//optimal approach would hasing and s-k appraoch
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int presum=0, cnt=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int remove=presum-k;
            cnt+=mpp[remove];
            mpp[presum]+=1;
        }
        return cnt;
    }
};


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
  cout<<endl;
  int k;
  cin>>k;
  int ans=subarraySum(arr,k);
  cout<<ans;
    return 0;
}