#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
       
  public:
  
  bool dfs(int node,vector<vector<int>> &adj,vector<int>& vis,vector<int>& path){
      vis[node]=1;
      path[node]=1;
      for(auto it:adj[node]){
          if(!vis[it] && dfs(it,adj,vis,path)) return true;
           else if(path[it]) return true;
      }
      
      path[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n =adj.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return true;
            } 
        }
        return false;
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}



int main(){
    vector<vector<int>> graph={{1},{2},{3},{4},{5}};
    Solution obj;
    cout<<obj.isCyclic(graph);
    return 0;
}