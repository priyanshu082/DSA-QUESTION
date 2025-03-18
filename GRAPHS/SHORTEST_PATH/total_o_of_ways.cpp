#include<iostream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> dist(n,1e12);
        vector<long long> ways(n,0);
        long long MOD=1e9+7;
        priority_queue< pair<long long,long long>,vector< pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        //{dist,node}
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

    int count=0;
        while(!pq.empty()){
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                long long newDist=dis + it.second + 0LL;
                if(newDist < dist[it.first]){
                    dist[it.first]=dis + it.second;
                    pq.push({newDist,it.first});
                    ways[it.first]=ways[node];
                } else if(newDist==dist[it.first]){
                    ways[it.first]+=ways[node];
                    ways[it.first]%=MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};

int main(){

    return 0;
}