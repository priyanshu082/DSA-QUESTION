//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int spanningTree(int V, vector<vector<int> > adj[]) {
        
        priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int mst=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            if(!vis[node]){
                vis[node]=1;
                mst+=wt;
                for(auto it : adj[node]){
                    int adjNode = it[0]; // destination node
                    int edgeWeight = it[1]; // weight is at index 2
                
                    if(!vis[adjNode]) pq.push({edgeWeight, adjNode});
                
                }
            } else continue;
        }
        
        return mst;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends