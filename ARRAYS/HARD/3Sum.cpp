#include<iostream>
#include<set>

using namespace std;

//brute force solution as here o(n@3) will be used and also sc 0(n);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
      
        set<vector<int>> set;
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                   if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    set.insert(temp);
                   }
               }
           }
       }

        vector<vector<int>> vec(set.begin(),set.end());
       return vec;
        
    }
};

//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum>0) k--;
            else if(sum<0) j++;
            else{
                vector<int> temp={nums[i],nums[j],nums[k]};
                vec.push_back(temp);
                k--;
                j++;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
            }
            }
            while(i+1 < n && nums[i]==nums[i+1]) i++;
        }
   
        return vec;
    }
};

int main(){

    return 0;
}