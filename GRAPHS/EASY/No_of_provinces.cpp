#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<int> &vis){
    vis[node]=1;
    for(int i=0;i<adj.size();i++){
        if(adj[node][i]==1 && !vis[i]){
            dfs(i,adj,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int> vis(V+1,0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                 dfs(i,isConnected,vis);
            }
        }

        return ans;
    }
};

int main(){
    
   return 0;
}