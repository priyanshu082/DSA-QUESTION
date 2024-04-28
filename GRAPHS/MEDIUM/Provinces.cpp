#include<iostream>
#include<vector>

using namespace std;

class Solution {
    private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node]=1;
        for(int it=0;it<isConnected[node].size();it++){
            if(isConnected[node][it] && !visited[it]){
                dfs(it,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len=isConnected.size();
    
        vector<int> adj[len];
     

        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

   vector<int> visited(len,0);
        int cnt=0;

        for (int i=0;i<len;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,isConnected,visited);
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}