#include<iostream>

using namespace std;

void primAlgo(vector<vector<pair<int,int>>>& adj,int V ){
    vector<int> dist(V,1e8);
    vector<int> vis (V,0);
    vector<int> parent(V,-1);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        vis[u]=1;
        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(!vis[v] && dist[v]>w+d){
                dist[v]=w+d;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }

    //printing the mst
    int sum = 0;
    cout << "Edges in MST:" << endl;
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

    int V,E;
    cout<<"Enter number vertices"<<endl;
    cin>>V;
    
    int** graph= new int*[V];

    for(int i=0;i<V;++i){
        graph[i]=new int[V];
    }

    for(int i =0;i<V;i++){
        cout<<"Enter the "<< i << " row of Matrix"<<endl;
        for(int j=0;j<V;j++){
            cin >> graph[i][j];
        }
    }

    for(int i =0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<< graph[i][j]<<" ";
        }
        cout<<endl;
    }

    //converting the graph to adjacency list
    vector<vector<pair<int,int>>> adj(V);
    for(int i =0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=0){
                adj[i].push_back({j,graph[i][j]});
            }
        }
    }

    //printing the adjcency list
    for(int i =0;i<V;i++){
        cout << i << ": ";
        for(auto it : adj[i]){
            cout << "(" << it.first << "," << it.second << ") ";
        }
        cout << endl;
    }

    int *visited = new int[V];
    int *minWeight = new int[V];
    int *parent = new int[V];
    
    for(int i = 0; i < V;i++){
        visited[i] = 0;
        minWeight[i] = INT_MAX;
        parent[i] = -1;
    }



    primAlgo(adj, V);

    for (int i = 0; i < V; ++i)
    delete[] graph[i];

    delete[] graph;

    return 0;

}