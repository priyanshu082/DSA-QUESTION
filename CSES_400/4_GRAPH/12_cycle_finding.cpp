#include<iostream>
#include<cmath>
#include<limits>
#include<vector>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    vector<int> parent(n + 1, -1);
    vector<long long> dist(n + 1, 0);

    // Bellman-Ford initialization: set all distances to 0 for cycle finding
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int x = -1;

    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (int j = 0; j < m; ++j) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int node = x;
        // Good question! In the last iteration, we do detect a node (x) that was relaxed,
        // but it's possible that x is not itself in the cycle, but rather is a descendant of a node in the cycle
        // (i.e., it was updated because of a chain of relaxations starting from the cycle).
        // By following parent pointers n times, we are guaranteed to reach a node that is actually inside the negative cycle,
        // because the cycle must be reachable within n steps in a graph of n nodes.
        for (int i = 0; i < n; ++i) {
            node = parent[node];
        }
        vector<int> path;
        int curr=node;
        do {
            path.push_back(curr);
            curr = parent[curr];
        } while (curr != node);
        path.push_back(node);
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}