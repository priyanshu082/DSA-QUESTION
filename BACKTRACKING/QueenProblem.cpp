#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> UpperLeftDiagonalCheck;
unordered_map<int,bool> LowerLeftDiagonalCheck;

void printSolution(vector<vector<char> > &board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row,int col,vector<vector<char> > &board ,int n){

    if(rowCheck[row]==true) return false;
    if(UpperLeftDiagonalCheck[n-1+col-row]==true) return false;
    if(LowerLeftDiagonalCheck[col+row]==true) return false;

    return true;

    //  int i=row;
    //  int j=col;

    //  //checking rows;
    //  while(j>=0){
    //     if(board[i][j]=='Q') return false;
    //     j--;
    //  }

    //  //checking upper side
    //  i=row;
    //  j=col;
    //  while(i>=0 && j>=0){
    //     if(board[i][j]=='Q') return false;
    //     j--;
    //     i--;
    //  }

    //  //checking lower side
    //  i=row;
    //  j=col;
    //  while(i<n && j>=0){
    //     if(board[i][j]=='Q') return false;
    //     j--;
    //     i++;
    //  }

    //  return true;

}

void solve(vector<vector<char> > &board,int col,int n){
        
        //base case
        if(col>=n) {
            cout<<endl;
            printSolution(board,n);
            return ;
        }

        //1 case solve krna h baaki recursion dekh  lega
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                //rakh do 
                board[row][col]='Q';

                rowCheck[row]=true;
                UpperLeftDiagonalCheck[n-1+col-row]=true;
                LowerLeftDiagonalCheck[row+col]=true;

                //baaki recrusion
                solve(board,col+1,n);

                //wapas hta do  queen ko
                board[row][col]='-';
                rowCheck[row]=false;
                UpperLeftDiagonalCheck[n-1+col-row]=false;
                LowerLeftDiagonalCheck[row+col]=false;
            }
        }
}

int main(){
    int n=4;
    vector<vector<char> > board(n,vector<char>(n,'-'));
    int col=0;
    solve(board,col,n);

    return 0;
}