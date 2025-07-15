#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> parent;
vector<int> construct(int n){
    vector<int> path;
    int curr=n;
    while(curr!=1){
        path.push_back(curr);
        curr=parent[curr];
    }
 path.push_back(1);
    reverse(path.begin(),path.end());
    return path;

}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,false);
    parent.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1]=true;
    parent[1]=1;
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                parent[it]=node;
                vis[it]=true;
                q.push({it,dist+1});
            }
        }
    }

    if(vis[n]){
        vector<int> path=construct(n);
        cout<<path.size()<<endl;
        for(auto it : path){
            cout<<it<<" ";
        }
        cout << endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
    
}