//{ Driver Code Starts
#include<iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int recursion(int row,int col1,int col2,int n,int m,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
      if(col1 < 0 || col1>m-1 || col2<0 || col2>m-1){
          return -1e8;
      }
      
      if(row==n-1){
          if(col1==col2){
              return grid[row][col1];
          }
          if(col1!=col2){
              return grid[row][col1]+grid[row][col2];
          }
      }
      
      if(dp[row][col1][col2]!=-1){
          return dp[row][col1][col2];
      }
      int maxi=0;
//explore all paths now
      for(int dCol1=-1 ; dCol1<=1;dCol1++){
          for(int dCol2=-1; dCol2<=1;dCol2++){
              int value;
              if(col1==col2) value=grid[row][col1];
              else value=grid[row][col1]+grid[row][col2];
              value+=recursion(row+1,col1+dCol1,col2+dCol2,n,m,grid,dp);
              maxi=max(maxi,value);
          }
      }
      return dp[row][col1][col2]=maxi;
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return recursion(0,0,m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends