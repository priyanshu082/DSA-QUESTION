#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> vis;

bool dfs(int node, int team)
{
    vis[node] = team;
    for (auto it : adj[node])
    {
        if (vis[it] == -1)
        {
           if (!dfs(it, 1 - team)) return false;
        }else if(vis[it]==team) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for (int i = 1; i <=n; i++)
    {
        if (vis[i] == -1 && !dfs(i,0))
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<vis[i]+1<<" ";
    }
    
    
}