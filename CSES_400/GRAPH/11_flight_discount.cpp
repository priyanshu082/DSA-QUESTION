#include<iostream>
#include<vector>
#include<limits>
#include<queue> 
#include <tuple>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main(){
    int n,m;
    cin>>n>>m;
    
   
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        
    }
    
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

    pq.push(make_tuple(0LL, 1, 0));
    dist[1][0]=0;
    
    while(!pq.empty()){
        auto [cost,node,used]=pq.top();
        pq.pop();
        if(dist[node][used] < cost ) continue;
        for(auto [v,w] : adj[node]){

            if(dist[v][used] > cost + w){
                dist[v][used] = cost + w;
                pq.push(make_tuple(dist[v][used], v,used));
            }

            if(!used){
                long long discount=w/2+cost;
                if(dist[v][1] > discount){
                    dist[v][1] = discount;
                    pq.push(make_tuple(dist[v][1], v,1));
                }
            }
        }
    }
    cout << dist[n][1] << endl;
    

    return 0;


}