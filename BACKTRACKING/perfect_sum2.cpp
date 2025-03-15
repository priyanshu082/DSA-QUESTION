//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
   
    bool checkSubsequenceSum(int n, vector<int>& arr, int target) {
       
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for( int j=0;j<=target;j++){
                if(arr[i-1]<=j) dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends