#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    cout<<"Enter the edges :"<<endl;

    vector<pair<int,int>> adj[n+1];

    for(int i = 0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    for(int i = 1;i<=n;i++){
        cout<<i<<"->";
        for(auto it: adj[i]){
            cout<<"("<<it.first<<", w:"<<it.second<<")"<<" ";
        }
        cout<<endl;
    }
    return 0;
}