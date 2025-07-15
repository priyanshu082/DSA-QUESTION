#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<vector<int>> adj;
vector<bool> vis;


void dfs(int node){
    vis[node]=true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> roads;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            roads.push_back(i);
            dfs(i);
        }
    }
    cout<<roads.size()-1<<endl;
    for(int i=1;i<roads.size();i++){
        cout<< roads[i-1] << " "<< roads[i]<<endl;
    }
    return 0;

}

