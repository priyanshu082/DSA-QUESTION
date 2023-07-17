#include<iostream>

using namespace std;

//brute force solution for this will be  select the row and column in which you get 0 and make seperate functions for converting that row and column elements to -1 which are not 0   and after that iterate the array and put all the element equal to 0 which is -1
//tc will be around n@3

//tc will be around n@2 and sc=o(n)+o(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1||col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};


//

int main(){
    
    int n,m;
    cin>>n>>m;
    int matrix[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j] << " ";
        }
        cout<<endl;
       
    }
    return 0;
}