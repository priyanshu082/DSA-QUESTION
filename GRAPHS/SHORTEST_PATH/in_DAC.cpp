//{ Driver Code Starts
// Initial Template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
       vector<vector<pair<int,int>>> adj(V);
       for(auto it : edges){
           int u =it[0];
           int v=it[1];
           int w=it[2];
           adj[u].push_back({v,w});
       }
       
       vector<int> dist(V , 1e9);
       queue<int> q;
       q.push(0);
       dist[0]=0;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto it: adj[node]){
               if(dist[node] + it.second< dist[it.first]){
                   dist[it.first]= it.second + dist[node];
                   q.push(it.first);
               }
           }
       }
       
       for( int i =0;i<V;i++){
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends