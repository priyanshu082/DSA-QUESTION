//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int func(vector<vector<int>> & points,int row,int last,vector<vector<int>> &dp){
      if(row==0){
          int maxi=0;
          for(int i=0;i<=2;i++){
              if(i!=last){
                  maxi=max(maxi,points[0][i]);
              }
          }
          return maxi;
      }
      
      if(dp[row][last]!=-1) return dp[row][last];
      
      int maxi=0;
      for(int i=0;i<=2;i++){
          if(i!=last) {
            int point=points[row][i]+func(points,row-1,i,dp);
            maxi=max(maxi,point);
          }
      }
     return dp[row][last] = maxi;
      
  }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
       
    vector<vector<int>> dp(n,vector<int>(4,-1));
       return func( points, n-1, 3,dp);
           
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends