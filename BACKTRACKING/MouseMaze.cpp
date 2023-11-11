#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i,int j,int row,int col,int arr[4][4],vector<vector<bool> > &visited)
{
    if(
    ((i>=0 && i<row) && (j>=0 && j<col))
    &&
    (arr[i][j]==1)
    &&
    (visited[i][j]==false)
    ) return true;
    else return false;  

}

void solvemaze(int arr[4][4],int row,int col ,int i,int j,vector<vector<bool> > &visited,vector<string> &path,string output )
{
  
        //base case
        if(i==row-1 && j==col-1) {
            //answer found 
            path.push_back(output);
            return;
        }

        //down
        if(isSafe(i+1,j,row,col,arr,visited)){
            visited[i+1][j]=true;
            solvemaze(arr,row,col,i+1,j,visited,path ,output+'D');
            visited[i+1][j]=false;
        }

        //left
         if(isSafe(i,j-1,row,col,arr,visited)){
            visited[i][j-1]=true;
            solvemaze(arr,row,col,i,j-1,visited,path ,output+'L');
            visited[i][j-1]=false;
        }

        //right
        if(isSafe(i,j+1,row,col,arr,visited)){
            visited[i][j+1]=true;
            solvemaze(arr,row,col,i,j+1,visited,path ,output+'R');
            visited[i][j+1]=false;
        }

        //up
        if(isSafe(i-1,j,row,col,arr,visited)){
            visited[i-1][j]=true;
            solvemaze(arr,row,col,i-1,j,visited,path ,output+'U');
            visited[i-1][j]=false;
        }

}


int main(){

    int maze[4][4]={{1,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

    if (maze[0][0]==0){
    cout<<"No path is Possible"<<endl;
    return 0;
    } 

    int row=4;
    int col=4;

    vector<vector<bool> > visited(row,vector<bool>(col,false));
    vector<string> path;
    string output="";

    visited[0][0]=true;
    solvemaze(maze,row,col,0,0,visited,path ,output);

    cout<<"Results"<<endl;
    for(string it:path){
        cout<<it<<endl;
    }
    cout<<endl;

    return 0;
}
     