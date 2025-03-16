
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            int u =it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }

        // vector<int> parent(n,-1);
        vector<int> dist(n,1e9);

        dist[src]=0;

      
        queue<pair<int,pair<int,int>>> q;

        //{dist,{node,stop}};
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            if(stop>=k+1);
            q.pop();
            for(auto it : adj[node]){
                if(stop<k+1 && dis + it.second < dist[it.first]){
                    dist[it.first]=dis+it.second;
                    q.push({stop+1,{it.first,dist[it.first]}});
                }
            }
            
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

int main(){
    return 0;
}