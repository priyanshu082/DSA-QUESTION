#include<iostream>
#include<vector>
#include<limits>
#include<queue>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    vector<vector<int>> adj(n+1);
    vector<long long> dist(n+1,INF);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,-w};
        adj[u].push_back(v);
       
    }

    dist[1]=0;
    for(int i=1;i<n;i++){
        for(auto it : edges){
            int u=it[0];int v=it[1];int w=it[2];
            if(dist[u]!=INF && dist[u]+w < dist[v]) dist[v]=dist[u]+w;
        }
    }

    vector<bool> inCycle(n+1,false);
    for(auto it : edges){
        int u=it[0];int v=it[1];int w=it[2];
        if(dist[u]!=INF && dist[u]+w  <  dist[v]) inCycle[v]=true;
    }

    vector<bool> vis(n+1,false);
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(inCycle[i]){
            q.push(i);
            vis[i]=true;
        } 
    }

    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push(it);
            }
        }
    }
    if(vis[n]) cout<<-1<<endl;
    else cout<<-dist[n]<<endl;

    return 0;
}