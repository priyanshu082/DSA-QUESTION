#include<iostream>
#include<vector>    
#include<queue>
using namespace std;

class Solution {
     
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, int color){
        vis[node]=color;
        for (auto it:graph[node]) if((vis[it]==-1 && !dfs(it,graph,vis,1-color)) || vis[it]==color) return false;
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++) if(vis[i]==-1 && !dfs(i,graph,vis,0)) return false;
        return true;
    }
};

int main(){
    vector<vector<int>> graph={{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution obj;
    cout<<obj.isBipartite(graph);
    return 0;
}