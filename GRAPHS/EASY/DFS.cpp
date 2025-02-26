#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}

int main(){
    int n, m;
    cout<<"Enter the number of vertices and edges :"<<endl;
    cin>>n>>m;

    vector<int> adj[n+1];
    for(int i=0 ;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //dfs
    vector<int> ans;
    vector<int> vis(n+1,0);
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,ans);
        }
    }
}