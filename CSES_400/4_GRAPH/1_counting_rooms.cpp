#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int n,m;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;

    Solution(vector<vector<char>> grid){
        this->grid=grid;
        this->n=grid.size();
        this->m=grid[0].size();
    }

    void dfs(int i,int j){
        visited[i][j]=true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        for(int p=0;p<4;p++){
            int newRow=i+drow[p];
            int newCol=j+dcol[p];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]=='.' && !visited[newRow][newCol]){
                dfs(newRow,newCol);
            }
        }
    }

    int countRooms(){
        visited=vector<vector<bool>>(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='.' && !visited[i][j]){
                    dfs(i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    int n ,m;
    cin>>n;
    cin>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    Solution solve(grid);
    cout<<solve.countRooms()<<endl;
    return 0;
}
