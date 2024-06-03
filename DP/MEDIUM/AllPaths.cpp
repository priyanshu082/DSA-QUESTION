#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:


// top down approach memoization appraoch 
int cnt(int m ,int n ,vector<vector<int>> dp){
    if(m<0 || n<0) return 0;
    if(m==0 && n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    int up=cnt(m-1,n,dp);
    int left=cnt(m,n-1,dp);
    int ans=up+left;
    dp[m][n]=ans;
    return ans;
}


//tabulation method
int uniquePaths2(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return cnt( m-1, n-1,dp);
    }

    int uniquePaths(int m, int n){
        
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up=0;int left=0;
                    if(i>0) up=dp[i-1][j];
                   if(j>0) left=dp[i][j-1];
                   dp[i][j]= up+left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){

}