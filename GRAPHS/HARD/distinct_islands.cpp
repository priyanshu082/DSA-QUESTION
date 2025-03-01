#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;


class Solution {
  public:
    
    void find_island(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& vec,int row0,int col0){
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        int tr=grid.size();
        int tc=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<tr && nrow>=0 && ncol<tc && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]){
               find_island(nrow,ncol,grid,vis,vec,row0,col0);
            }
        }
    }
    
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int tr=grid.size();
        int tc =grid[0].size();
        vector<vector<int>> vis(tr, vector<int>(tc,0));
        
        set<vector<pair<int,int>>> st;
        for(int i=0;i<tr;i++){
            for(int j=0;j<tc;j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>> vec;
                    find_island(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                } 
            }
        }
        return st.size();
    }
};
    

int main(){
    vector<vector<int>> grid={{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    Solution obj;
    cout<<obj.countDistinctIslands(grid);
    return 0;
}