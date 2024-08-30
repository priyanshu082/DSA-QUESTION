#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_SIZE 100
#define MAX_NEIGHBOURS 20

class MinHeap
{
private:
    int heap[MAX_SIZE][3]; // Removed default initialization
    int size;

public:
    MinHeap() : size(0) // Initialize size in the constructor
    {
        memset(heap, 0, sizeof(heap)); // Initialize heap with 0
    }

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

        //take a new array by alloccating memory dynamically
        // root ko humne new root variable bna k usme store krva dia
        int *root = new int[3];
        root[0] = heap[1][0];
        root[1] = heap[1][1];
        root[2] = heap[1][2];

// heap[last] ko 0 index pr shift krdo 
        heap[1][0] = heap[size][0];
        heap[1][1] = heap[size][1];
        heap[1][2] = heap[size][2];

        // size ko decrease krdia
        size--;

//ab dubara se heapify down krdia jisase last waala jo humne root pr shift kia th 
// vo wapas se apni shi jgh pr jaa ske
        int i = 1;
        while (i <= size)
        {
            //uske dono children ko access krne ka trika
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;

    //ab yha pr pata kia jyega ki dono children m se chota kon hai
            int smallest = i;
            if (leftIdx <= size && heap[smallest][0] > heap[leftIdx][0])
            {
                smallest = leftIdx;
            }
            if (rightIdx <= size && heap[smallest][0] > heap[rightIdx][0])
            {
                smallest = rightIdx;
            }

//jo bhi chota children hai usko ab swap krdenge
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
        return root;
    }
};

void mst(int adj[][MAX_NEIGHBOURS][2], int V)
{
    MinHeap heap;

    bool *visited = new bool[V](); // Use dynamic allocation
    int **mstEdges = new int *[V - 1]; // Array to store MST edges
    for (int i = 0; i < V - 1; ++i)
    {
        mstEdges[i] = new int[3]; // Each edge will have {u, v, w}
    }

    int totalWeight = 0; // To store the total weight of the MST

    int startNode = 0;
    visited[startNode] = true;

//yha pr hum min heap m data ko add kr rhe hai 
    for (int i = 0; i < MAX_NEIGHBOURS && adj[startNode][i][0] != -1; ++i)
    {
        int edge[3] = {adj[startNode][i][1], adj[startNode][i][0], startNode}; 
        heap.add(edge);
    }

    //no of edge count zada na ho jye uske liye
    int edgeCount = 0;

    while (!heap.isEmpty() && edgeCount < V - 1)
    {
        int *minEdge = heap._pop(); 
        int weight = minEdge[0];
        int node = minEdge[1];
        int parent = minEdge[2];

        if (visited[node])
        {
            delete[] minEdge; 
            continue;
        }

        visited[node] = true;

        mstEdges[edgeCount][0] = parent;
        mstEdges[edgeCount][1] = node;
        mstEdges[edgeCount][2] = weight;
        edgeCount++;

        totalWeight += weight;

        for (int i = 0; i < MAX_NEIGHBOURS && adj[node][i][0] != -1; ++i)
        {
            int nextNode = adj[node][i][0];
            int nextWeight = adj[node][i][1];

            if (!visited[nextNode])
            {
                int edge[3] = {nextWeight, nextNode, node}; 
                heap.add(edge);
            }
        }

        delete[] minEdge; 


    }

    cout << "Final Minimum sum of edges in MST: " << totalWeight << endl;

     cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 0; i < V - 1; ++i)
    {
        cout << "Edge from " << mstEdges[i][0] << " to " << mstEdges[i][1] << " with weight " << mstEdges[i][2] << endl;
    }


    delete[] visited;
}

int main()
{
    cout << "# Welcome to Prim's algorithm program" << endl;
    cout << "[edgeWt,node,parent] is the format in which element are inserted in priority queue" << endl;
    cout << "[parent,node,edgeWt] is the format of mst" << endl;

    
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
            adj[i][j][0] = -1;
            adj[i][j][1] = -1;
        }
    }

    int *neighborCount = new int[V](); // Dynamic allocation

    // cout << "Enter the graph in format(u v w), where u and v are source and destination respectively and w is the edge weight" << endl;
    for (int i = 0; i < edges; ++i)
    {
        cout << "Enter the graph in format(u v w), where u and v are source and destination respectively and w is the edge weight" << endl;
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

   
    
    delete[] neighborCount; // Free dynamically allocated memory

    return 0;
}
