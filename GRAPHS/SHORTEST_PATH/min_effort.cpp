#include<iostream>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int r[]={-1,0,1,0};
        int c[]={0,-1,0,1};
      
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int n =h.size();
        int m=h[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i =0;i<4;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 ){
                    int newEffort=max(abs(h[row][col]-h[nrow][ncol]),diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};


int main(){
    return 0;
}