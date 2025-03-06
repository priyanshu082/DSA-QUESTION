#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Solution {
public:
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int> q;
        vector<int> indegree(n, 0);

        // Compute indegree of each node
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Push nodes with 0 indegree into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; // Count of processed nodes

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        // If count == n, then no cycle (DAG), otherwise cycle exists
        return count != n;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    Solution obj;
    cout << obj.isCyclic(adj) << endl;

    return 0;
}

