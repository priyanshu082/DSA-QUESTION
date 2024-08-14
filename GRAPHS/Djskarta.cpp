#include <iostream>
#include<queue>
using namespace std;

// maxheap
class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        };
    }

    void heapifyDown()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 0;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// heapifyUp algo
void heapifyUp(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyUp(arr, n, largest);
    }
}


void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapifyUp(arr,size,1);
    }
}

//djkarta using pq
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V);

    for(int i=0;i<V;i++) dist[i]=1e9;

    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
            int dis=pq.top().first;  
            int node=pq.top().second;
            pq.pop();

            //exploring the adjacent node
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];

                if(dis+edgeWeight<dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
    }
    return dist;
}

int main()
{
    // djkarta algorithm
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();

    int arr[6]={-1,54,53,55,52,50};
    int n = 5;

    for (int i = n / 2 ; i > 0;i--){
        heapifyUp(arr, n, i);
    }   

    for (int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    

    heapSort(arr,n);

    for (int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    //using priority queue
    priority_queue<int> pq;
 
    return 0;
}