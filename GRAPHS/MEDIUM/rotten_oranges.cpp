#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
        int size=grid.size();
        int col=grid[0].size();
        int time=0;
        int fresh=0;
        vector<vector<int>> vis(size, vector<int> (col,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<size;i++){
            for (int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                } else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty()){
            
            int i = q.front().first.first;
            int j = q.front().first.second;

            int tm=q.front().second;
            time=max(time,tm);
            q.pop();
            for(int k=0;k<4;k++){
                int nrow= i+drow[k];
                int ncol= j+dcol[k];
                if(nrow >=0 && nrow<size && ncol>=0 && ncol<col && vis[nrow][ncol]==0 && grid[nrow][ncol]==1 ){
                    q.push({{nrow,ncol},tm+1});
                    grid[nrow][ncol]=2;
                    vis[nrow][ncol]=2;
                    fresh--;
                }
            } 
        }
        return fresh==0 ? time : -1;  
    }
};

int main(){
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the grid (0 for empty, 1 for fresh orange, 2 for rotten orange):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    Solution obj;
    int result = obj.orangesRotting(grid);
    cout << "The minimum time taken for all oranges to rot is: " << result << endl;

    return 0;
}