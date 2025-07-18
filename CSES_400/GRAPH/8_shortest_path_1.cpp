#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For LLONG_MAX

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<long long> dist;

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    dist.assign(n + 1, LLONG_MAX);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;  

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
