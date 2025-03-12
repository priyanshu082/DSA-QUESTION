//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {

       int n = adj.size();
        
       
        queue<int> q;
        vector<int> dist(n, 1e9);
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node =q.front();
            int dis=dist[node];
            q.pop();
            for(auto it: adj[node]){
                if(dis+1<dist[it]){
                    dist[it]=1+dis;
                    q.push(it);
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
       
       return dist;
    }
};


//{ Driver Code Starts.
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends