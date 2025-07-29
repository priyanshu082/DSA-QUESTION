#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;



int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> count(n + 1, 0);
    vector<ll> result;
    pq.push({(ll)0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        ll dist = pq.top().first;
        pq.pop();

        if (count[node] >= k)
            continue;

        count[node]++;

        if (node == n)
            result.push_back(dist);
        if (result.size() == k)
            break;

        for (auto it : adj[node])
        {
            int next = it.first;
            ll cost = it.second;
            pq.push({dist + cost, next});
        }
    }

    for (ll c : result)
    {
        cout << c << " ";
    }
    return 0;
}
