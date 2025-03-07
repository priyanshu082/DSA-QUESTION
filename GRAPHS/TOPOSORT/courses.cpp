#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
int N = pre.size();
vector<int> topo;
if(N==0){
    for(int i=numCourses-1;i>=0;i--){
        topo.push_back(i);
    }

    return topo;
}
        vector<vector<int>> adj(numCourses);

       
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        

        vector<int> indegree(numCourses,0);
        for(int i =0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
        }
        if(topo.size()==numCourses) return topo;
        else return {};
        // return topo.size()==numCourses;
    }
};

int main(){
    Solution s;
    vector<vector<int>> pre = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = s.findOrder(4,pre);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}