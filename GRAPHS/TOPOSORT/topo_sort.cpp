#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void dfs(stack<int>& st,vector<int>& vis,int i ,vector<vector<int>>& adj){
      vis[i]=1;
      for(auto it: adj[i]){
          if(!vis[it]){
              dfs(st,vis,it,adj);
          }
          st.push(it);
      }
      
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
         vector<int> vec;
        stack<int> st;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(st,vis,i,adj);
            }
        }
        
        while(!st.empty()){
           vec.push_back(st.top());
           st.pop();
        }
        
        return vec;
    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends   