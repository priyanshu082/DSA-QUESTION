#include<iostream>

using namespace std;

//binary serch when row and col are sorted separately but the matrix is not sorted
 bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        int col=mat[0].size();

        int rowIndex=0;
        int colIndex=col-1;
        while(rowIndex<row && colIndex>=0){
            int ele=mat[rowIndex][colIndex];

            if(ele==target) return true;
            else if(ele<target) rowIndex++;
            else colIndex--;
        }
        return false;
    }

int main(){

    return 0;
}