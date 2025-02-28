#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
 int dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& board){
        vis[row][col]=1;
        int count =1;
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && !vis[nrow]  [ncol] && board[nrow][ncol]==1){
                count+=dfs(nrow,ncol,vis,board);
            }
        }
        return count;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int tr=grid.size();
        int tc=grid[0].size();
        int canVis=0;
        int total=0;
        vector<vector<int>> vis(tr,vector<int>(tc,0));
        for(int i=0;i<tr;i++){
            for(int j=0;j<tc;j++){
                if(grid[i][j]) total++;
                 if( (i==0 || i==tr-1 || j==0 || j==tc-1) && !vis[i][j] && grid[i][j]) canVis += dfs(i,j,vis,grid);
                
            }
        }
        return total-canVis;
    }
};


int main(){
    vector<vector<int>> grid={{0,1,1,0},{1,1,1,0},{0,1,1,0},{0,0,0,0}};
    int n=4;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> ans(n,vector<int>(n,0));
    Solution obj;
    cout<<obj.numEnclaves(grid);    
    return 0;
}