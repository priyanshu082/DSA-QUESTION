#include<iostream>

using namespace std;

const int MAX=100;

int main(){
    int n;
    cout<<"Enter the number of vertices "<<endl;
    cin>> n ;
    int adj[MAX][MAX]={0};
    cout<< "Enter the edges of the graph "<<endl;
    int m;
    cin>> m;
    cout << "Enter the edges (u v):" << endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u;
        cin>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adj[i][j]==0) cout<<"_"<<"  ";
            else cout<< adj[i][j]<<"  ";
        }
        cout<<endl;
        cout<<endl;
    }

    return 0;
}