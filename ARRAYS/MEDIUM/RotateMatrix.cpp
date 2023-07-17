#include<iostream>

using namespace std;

//brute force solution sc=n@2 and tc=2n@2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

     vector<vector<int>> matrix2(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             matrix2[j][n-1-i]=matrix[i][j];
         }
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             matrix[i][j]=matrix2[i][j];
         }
     }

   
    }
};

//optimal appraoch  for taking transpose of matrix we use n/2*n/2     and for reversing we use n*n/2
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n-1;i++){
         for(int j=i+1;j<m;j++){
           swap(matrix[i][j],matrix[j][i]);
         }
        }
       
       for(int i=0;i<n;i++){
           reverse(matrix[i].begin(),matrix[i].end());
       }
        

    }
};




int main(){

    return 0;
}