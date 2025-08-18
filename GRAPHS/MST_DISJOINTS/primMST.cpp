#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

/*
    Prim's Algorithm for Minimum Spanning Tree (MST)
    ------------------------------------------------
    Why: To find a subset of edges that connects all vertices in the graph with the minimum possible total edge weight, and no cycles.

    What: We use a priority queue (min-heap) to always pick the edge with the smallest weight that connects a new vertex to the growing MST.

    How: 
    - We maintain three arrays:
        1. dist: Minimum weight to connect each vertex to the MST.
        2. vis: To mark if a vertex is already included in the MST.
        3. parent: To store the parent of each vertex in the MST (for reconstructing the MST).
    - We start from vertex 0, push it into the priority queue with weight 0.
    - At each step, pick the vertex with the smallest edge weight not yet in the MST.
    - For each neighbor, if it is not in the MST and the edge weight is less than its current dist, update dist and parent, and push into the queue.
    - After the loop, parent[] gives the MST structure.
*/

void primAlgo(vector<vector<pair<int,int>>>& adj, int V ){
    // dist[i]: Minimum weight to connect i to MST
    vector<int> dist(V, INT_MAX);
    // vis[i]: Whether i is already in MST
    vector<int> vis(V, 0);
    // parent[i]: Parent of i in MST
    vector<int> parent(V, -1);

    // Min-heap: (weight, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Start from vertex 0
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        int u = pq.top().second; // Current vertex
        int d = pq.top().first;  // Current weight
        pq.pop();

        // If already visited, skip
        if(vis[u]) continue;
        vis[u] = 1;

        // For all adjacent vertices
        for(auto it : adj[u]){
            int v = it.first;   // Neighbor
            int w = it.second;  // Edge weight

            // If v not in MST and edge u-v is better than current best
            if(!vis[v] && dist[v] > w){
                dist[v] = w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Printing the MST
    int sum = 0;
    cout << "\nEdges in MST:" << endl;
    for(int i = 1; i < V; i++) {
        if(parent[i] != -1) {
            // Find the weight of the edge from parent[i] to i
            int weight = 0;
            for(auto it : adj[i]) {
                if(it.first == parent[i]) {
                    weight = it.second;
                    break;
                }
            }
            cout << parent[i] << " - " << i << " (weight: " << weight << ")" << endl;
            sum += weight;
        }
    }
    cout << "Total weight of MST: " << sum << endl;
}

int main (){
    /*
        Step 1: Input the graph as an adjacency matrix.
        Why: It's a common way to represent dense graphs and easy for user input.
    */
    int V;
    cout << "Enter number of vertices:" << endl;
    cin >> V;

    // Dynamically allocate adjacency matrix
    int** graph = new int*[V];
    for(int i = 0; i < V; ++i){
        graph[i] = new int[V];
    }

    // Input the adjacency matrix
    for(int i = 0; i < V; i++){
        cout << "Enter the " << i << " row of Matrix:" << endl;
        for(int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }

    // Print the adjacency matrix for verification
    cout << "\nAdjacency Matrix:" << endl;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    /*
        Step 2: Convert adjacency matrix to adjacency list.
        Why: Adjacency list is more efficient for sparse graphs and easier to use with Prim's algorithm.
        What: For each non-zero entry in the matrix, add an edge to the adjacency list.
    */
    vector<vector<pair<int,int>>> adj(V);
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(graph[i][j] != 0){
                adj[i].push_back({j, graph[i][j]});
            }
        }
    }

    // Print the adjacency list for verification
    cout << "\nAdjacency List:" << endl;
    for(int i = 0; i < V; i++){
        cout << i << ": ";
        for(auto it : adj[i]){
            cout << "(" << it.first << "," << it.second << ") ";
        }
        cout << endl;
    }

    /*
        Step 3: Run Prim's algorithm to find the MST.
        Why: To get the minimum spanning tree and its total weight.
    */
    primAlgo(adj, V);

    // Clean up dynamically allocated memory
    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;

    return 0;
}