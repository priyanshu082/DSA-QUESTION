#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
    vector<int> topoSort(int n, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it :adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> vec;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vec.push_back(node);
            for(auto it :adj[node]){
                if(indegree[it]>0){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
        }
        
        return vec;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution obj;
    vector<int> ans = obj.topoSort(n,adj);
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}