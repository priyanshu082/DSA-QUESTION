#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n ,m;
    cin>>n>>m;

    // Correcting adjacency matrix size and initializing with zeros
    int adj[n+1][n+1];  // Use n+1 x n+1 instead of n+1 x m+1
    vector<int> adjlist[n+1];

    cout<<"Enter the edges :"<<endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    cout<<"The adjacency matrix is :"<<endl;
    for(int i = 1; i <= n; i++){   // Change loop range to n
        for(int j = 1; j <= n; j++){  // Also loop till n instead of m
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The adjacency list is :"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<i<<"->";
        for(auto it: adjlist[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}
