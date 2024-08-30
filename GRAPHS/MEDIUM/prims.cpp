#include <iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX_NEIGHBOURS 20

class MinHeap
{
private:
    int heap[MAX_SIZE][3] = {0}; // edgewt,node,parent
    int size = 0;

public:
    void add(int arr[3])
    {
        size = size + 1;
        int index = size;
        for (int i = 0; i < 3; ++i)
        {
            heap[index][i] = arr[i];
        }
        while (index > 1)
        {
            int parent = index / 2;
            if (heap[parent][0] >= heap[index][0])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
                break;
        }
        cout << "After adding {" << arr[0] << ", " << arr[1] << ", " << arr[2] << "} to the heap:" << endl;
        print();
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Priority queue is empty" << endl;
            return;
        }
        for (int i = 1; i <= size; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << heap[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int *_pop()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return nullptr;
        }

        // Store the root element (which is to be removed) in a temporary array
        int *root = new int[3];
        root[0] = heap[1][0];
        root[1] = heap[1][1];
        root[2] = heap[1][2];

        // Replace the root with the last element in the heap
        heap[1][0] = heap[size][0];
        heap[1][1] = heap[size][1];
        heap[1][2] = heap[size][2];
        size--;

        // Heapify down to maintain the min-heap property
        int i = 1;
        while (i <= size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;

            int smallest = i;
            if (leftIdx <= size && heap[smallest][0] > heap[leftIdx][0])
            {
                smallest = leftIdx;
            }
            if (rightIdx <= size && heap[smallest][0] > heap[rightIdx][0])
            {
                smallest = rightIdx;
            }

            if (smallest != i)
            {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
            {
                break;
            }
        }

        cout << "After removing {" << root[0] << ", " << root[1] << ", " << root[2] << "} from the heap:" << endl;
        print();
        return root; // Return the original root element
    }
};

void mst(int adj[][MAX_NEIGHBOURS][2], int V)
{
    MinHeap heap;
    bool visited[V] = {false};         // Visited array
    int **mstEdges = new int *[V - 1]; // Array to store MST edges
    for (int i = 0; i < V - 1; ++i)
    {
        mstEdges[i] = new int[3]; // Each edge will have {u, v, w}
    }

    int totalWeight = 0; // To store the total weight of the MST

    // Start with node 0, we assume node indices are from 0 to V-1
    int startNode = 0;
    cout << "Initial visited array:" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << visited[i] << " ";
    }
    cout << endl;

    visited[startNode] = true;

    // Push all edges from the start node to the heap
    for (int i = 0; i < MAX_NEIGHBOURS && adj[startNode][i][0] != -1; ++i)
    {
        int edge[3] = {adj[startNode][i][1], adj[startNode][i][0], startNode}; // {weight, node, parent}
        heap.add(edge);
    }

    int edgeCount = 0;

    // While the heap is not empty and the MST has fewer than V-1 edges
    while (!heap.isEmpty() && edgeCount < V - 1)
    {
        cout << "Current visited array:" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << visited[i] << " ";
        }
        cout << endl;

        int *minEdge = heap._pop(); // Get the edge with the minimum weight
        int node = minEdge[1];
        int weight = minEdge[0];
        int parent = minEdge[2];

        cout << "Processing edge {" << parent << ", " << node << ", " << weight << "}" << endl;

        // If the node is already visited, skip this edge
        if (visited[node])
        {
            delete[] minEdge; // Free the dynamically allocated memory
            continue;
        }

        // Mark the node as visited
        visited[node] = true;

        // Add this edge to the MST
        mstEdges[edgeCount][0] = parent;
        mstEdges[edgeCount][1] = node;
        mstEdges[edgeCount][2] = weight;
        edgeCount++;

        // Add the weight to the total weight
        totalWeight += weight;

        cout << "Edge {" << parent << ", " << node << ", " << weight << "} added to MST." << endl;
        cout << "Current MST total weight: " << totalWeight << endl;
        cout << "-------------------------" << endl;

        // Push all edges from the current node to the heap
        for (int i = 0; i < MAX_NEIGHBOURS && adj[node][i][0] != -1; ++i)
        {
            int nextNode = adj[node][i][0];
            int nextWeight = adj[node][i][1];

            if (!visited[nextNode])
            {
                int edge[3] = {nextWeight, nextNode, node}; // {weight, node, parent}
                heap.add(edge);
            }
        }

        delete[] minEdge; // Free the dynamically allocated memory
    }

    // Final display of MST weight
    cout << "Final visited array" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
    cout << "Final Minimum sum of edges in MST: " << totalWeight << endl;
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 0; i < V - 1; ++i)
    {
        cout << "Edge from " << mstEdges[i][0] << " to " << mstEdges[i][1] << " with weight " << mstEdges[i][2] << endl;
    }

    
}

int main()
{
    cout<<"#Welcome to Prim's alogrithm program"<<endl;
    cout<<"[edgeWt,node,parent] is the format in which element are inserted in priority queue"<<endl;
    cout<<"[parent,node,edgeWt] is the format of mst"<<endl;
    int V, edges;
    cout << "Enter the number of vertices" << endl;
    cin >> V;
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    int adj[V][MAX_NEIGHBOURS][2];
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < MAX_NEIGHBOURS; ++j)
        {
            adj[i][j][0] = -1; // No node connected initially
            adj[i][j][1] = -1; // No weight associated
        }
    }

    int neighborCount[V] = {0};

    cout << "Enter the graph in format(u v w), where u and v are source and destination respectively and w is the edge weight" << endl;
    for (int i = 0; i < edges; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][neighborCount[u]][0] = v;
        adj[u][neighborCount[u]][1] = w;
        neighborCount[u]++;

        adj[v][neighborCount[v]][0] = u;
        adj[v][neighborCount[v]][1] = w;
        neighborCount[v]++;
    }

   mst(adj, V);


    return 0;
}