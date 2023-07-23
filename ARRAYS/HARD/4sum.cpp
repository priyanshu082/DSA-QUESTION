#include<iostream>

using namespace std;

// one soltuon will running four loops tc=o(n@4) 


//another soltuion will running 3 loops tc=o(n@3)

//another solution will be running 2 loops and running while loop inside  timer complxxity will be o(n@2 log n ) because sorting will take up take time =nlogn
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-3;i++){
            if( i>0 && nums[i]==nums[i-1])
            continue;

            for(int l=n-1 ;l>=i+2;l--){
                 if(l<n-1 && nums[l]==nums[l+1])
            continue;
                long long sum1=nums[i]+nums[l];
            long long sum2=target-sum1;
            int j=i+1;
            int k=l-1;
            while(j<k){
                    if(nums[j]+nums[k]==sum2){
               ans.push_back({nums[i],nums[j],nums[k],nums[l]});
              while(j<k && nums[j]==nums[j+1]) j++;
              while(j<k && nums[k]==nums[k-1]) k--;

              j++;
              k--;
            } else if(nums[j]+nums[k]>sum2){
               k--;
            } else if(nums[j]+nums[k]<sum2){
               j++;
            }
            } 
            }
            
        }

        return ans;
    }
};

// more optimal approach but tc is almost same i.e o(n@2logn)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-3;i++){
            if( i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<=n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>target) l--;
                    else k++;
                }

            }
            
        }

        return ans;
    }
};



int main(){

    return 0;
}