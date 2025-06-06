#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 bool detect(int src, vector<vector<int>>& adj, vector<int>& vis){
      queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
       
        while(!q.empty()){
            int node=q.front().first;
            int come_from=q.front().second;
            q.pop();
            for (auto it: adj[node]){
                if(!vis[it] ) {
                    vis[it]=1;
                    q.push({it,node});
                }  else if(come_from != it) return true;
            }
        }
        return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]) {
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }


int main(){
    vector<vector<int>> adj={{1,2},{2,3},{3,4},{4,5},{5,1}};
    int n=5;
    vector<int> vis(n+1,0);
    vector<int> dfs(n+1,0);
    
}