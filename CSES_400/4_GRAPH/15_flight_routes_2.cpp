#include<iostream>
#include<vector>
#include <algorithm>



using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis, recStack;
vector<int> cycle;

bool dfs(int node){
    vis[node]=true;
    recStack[node]=true;
    for(auto it : adj[node]){
        if(!vis[it]){
            parent[it]=node;
            if(dfs(it)) return true;
        }else if(recStack[it]){
            cycle.push_back(it);
            int cur=node;
            while(cur!=it){
                cycle.push_back(cur);
                cur=parent[cur];
            }
            cycle.push_back(it);
            reverse(cycle.begin(), cycle.end());
            return true;
        }

    }
    recStack[node]=false;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    recStack.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bool found=false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                found = true;
                break;
            }
        }
    }

    if(found){
        cout<< cycle.size()<<endl;
        for(auto it : cycle) cout<< it<<" ";
    }else cout<<"IMPOSSIBLE"<<endl;

    

    return 0;
}
