#include<iostream>
#include<cmath>
#include<limits>
#include<vector>

using namespace std;

const long long INF = numeric_limits<long long>::max(); 

int main(){
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>> dist(n+1,vector<long long>(n+1,INF));
    for(int i=1; i<=n; ++i){
        dist[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = min(dist[u][v], (long long)w);
dist[v][u] = min(dist[v][u], (long long)w);
    }

    vector<pair<int,int>> query;
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        query.push_back({u,v});
    }   

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(auto it: query){
        int u = it.first;
        int v = it.second;
        if(dist[u][v] != INF){
            cout<<dist[u][v]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}