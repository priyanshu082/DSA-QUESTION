#include<iostream>

using namespace std;

class Solution {
public:

    int shortestPathBinaryMatrix2(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r[]={-1,0,1,0,-1,-1,+1,+1};
        int c[]={0,-1,0,1,-1,+1,-1,+1};
        int n=grid.size();

        vector<vector<int>> vis(n ,vector<int>(n, 0));

        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        q.push({0,0});
        vis[0][0]=1;
        int steps=1;

        while(!q.empty()){
           int size=q.size();

           for(int k=0;k<size;k++){
            auto [row ,col] = q.front();
            if(row==n-1 && col==n-1) return steps;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !grid[nrow][ncol] && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
           }
           steps++;
           
        }
       return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int r[]={-1,0,1,0,-1,-1,+1,+1};
        int c[]={0,-1,0,1,-1,+1,-1,+1};
        int n=grid.size();
        vector<vector<int>> dist(n ,vector<int>(n, 1e9));
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !grid[nrow][ncol] && dis+1 < dist[nrow][ncol]){
                    dist[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];
    }
};

int main(){
    return 0;
}