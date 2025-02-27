#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& adj) {
        int trow =adj.size();
        int tcol= adj[0].size();

        vector<vector<int>> vis(trow,vector<int>(tcol,0));
        vector<vector<int>> dist(trow,vector<int>(tcol,0));

        queue<pair<pair<int,int>,int>> q;
        for(int i =0;i<trow;i++){
            for(int j=0;j<tcol;j++){
                if(adj[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

          int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;
          
            for(int i=0;i<4;i++){
                int nrow= row + drow[i];
                int ncol=col + dcol[i];    
                if(nrow>=0 && ncol>=0 && nrow<trow && ncol<tcol && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }     
            }
        }
        return dist;
    }
};


int main(){
    vector<vector<int>> grid={{0,1},{1,0}};
    int n=2;
    vector<vector<int>> vis(n,vector<int>(n,0));
    queue<pair<int,int>> q;
    
}