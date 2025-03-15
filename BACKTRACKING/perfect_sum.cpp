//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int r(int target,vector<int>& arr,int i,vector<vector<int>>& dp){
        if(target==0) return 1;
        
        if(i>=arr.size() || target<0 ) return 0;
        
        
        
        if(dp[i][target]!=-1) return dp[i][target];
        
       int include=0;
         if(arr[i]!=0) include=r(target-arr[i],arr,i+1,dp);
        int exclude=r(target,arr,i+1,dp);
        
        return dp[i][target]=include+exclude;
         
  }
  
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n =arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        
        int count=r(target,arr,0,dp);
        
        int zero=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) zero++;
        }
        
        
         return count * (1<< zero);
    }
};


//{ Driver Code Starts.

int main() {
   
    return 0;
}

// } Driver Code Ends