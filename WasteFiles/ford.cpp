#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

bool bfs(vector<vector<int> >& residualGraph, int source, int sink, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink) return true;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int> >& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int> > residualGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        cout << "Augmenting path found: ";
        vector<int> path;
        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path.push_back(v);
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        path.push_back(source);
        reverse(path.begin(), path.end());

        for (int i=0;i<path.size();i++) cout << path[i] << " ";
        cout << "\nPath flow: " << pathFlow << endl;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            // residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
				
        cout << "Updated residual graph:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << residualGraph[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------" << endl;
    }

    return maxFlow;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int> > graph(n, vector<int>(n, 0));

    cout << "Enter the edges and their capacities (format: u v capacity):\n";
    for (int i = 0; i < m; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    int source, sink;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the sink vertex: ";
    cin >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "The maximum possible flow is: " << maxFlow << endl;

    return 0;
}
