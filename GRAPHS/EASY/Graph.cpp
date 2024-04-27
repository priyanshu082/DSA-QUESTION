#include <iostream>
#include<vector>

using namespace std;

int main()
{

    // but this method is taking o(n^2) space
    int n, m;
    cin >> n >> m;
    int adj[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //method 2 
    vector<int> a[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u >>v ;
        a[u].push_back(v);
    }

    return 0;
}