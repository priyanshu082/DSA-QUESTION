//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void r(vector<int>& arr,vector<int>& ans,int i,int sum ){
        
        if(i>=arr.size()) {
            ans.push_back(sum);
            return;
        };
        
        // ans.push_back(sum)
        r(arr,ans,i+1,sum);
        r(arr,ans,i+1,sum+arr[i]);
        
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        r(arr,ans,0,0);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  

    return 0;
}

// } Driver Code Ends