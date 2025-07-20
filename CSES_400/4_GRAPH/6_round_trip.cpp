#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;

vector<int> construct(int start,int end)
{
    vector<int> path;
    int curr = start;
    
    while (curr != end)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(end);
    reverse(path.begin(), path.end());
     path.push_back(end);
    return path;
}

bool dfs(int node, vector<int> &cycle)
{
    for (auto it : adj[node])
    {
        if (parent[it]==0)
        {
            parent[it] = node;
            if (dfs(it, cycle)) return true;
        }
        else if (parent[node] != it)
        {
            cycle = construct(node,it);
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    parent.assign(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cycle;
    for (int i = 1; i <= n; i++)
    {
        if (!parent[i])
        {
            parent[i]=-1;
            if (dfs(i, cycle))
            {
                cout << cycle.size() << endl;
                for (int x : cycle)
                    cout << x << " ";
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
