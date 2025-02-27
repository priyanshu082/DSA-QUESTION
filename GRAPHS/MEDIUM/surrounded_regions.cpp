#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int tr=board.size();
        int tc=board[0].size();
        vector<vector<int>> vis(tr, vector<int>(tc,0));



        for(int i=0;i<tc;i++){
            //first row
           if(!vis[0][i] && board[0][i]!='X') dfs(0,i,vis,board);

           //last row
           if(!vis[tr-1][i] && board[tr-1][i]!='X') dfs(tr-1,i,vis,board);
        }

        for(int j=0;j<tr;j++){
            //first col
            if(!vis[j][0] && board[j][0]!='X') dfs(j,0,vis,board);

            //last col
           if(!vis[j][tc-1] && board[j][tc-1]!='X') dfs(j,tc-1,vis,board);
        }

        for(int i=0;i<tr;i++){
            for(int j=0;j<tc;j++){
                if(!vis[i][j]) board[i][j] = 'X';
                else board[i][j]='O';
            }
        }
    }
};



int main(){
    vector<vector<char>> board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    int n=4;
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> ans(n,vector<int>(n,0));
    Solution obj;
    obj.solve(board);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}