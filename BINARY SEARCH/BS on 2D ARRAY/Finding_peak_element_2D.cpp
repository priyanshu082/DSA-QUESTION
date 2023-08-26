#include<iostream>

using namespace std;

//not as binary search but optimal approach 
 vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();

            int i=0,j=col-1;
        while(i<row && i>=0 && j>=0 && j<col){
            int ele=mat[i][j];
            int up=i-1<0 ? -1 : mat[i-1][j];
            int down=i+1>=row ? -1 : mat[i+1][j];
            int left=j-1<0 ? -1 : mat[i][j-1];
            int right=j+1>=col ? -1 : mat[i][j+1];

            if(ele>max(max(up,down),max(left,right))) return {i,j};
              int maxi=max(max(up,down),max(left,right));

              if(maxi==up) i--;
              else if(maxi==down) i++;
              else if(maxi==left) j--;
              else if(maxi==right) j++;
        }
        return {-1,-1};
    }

int main(){
    
    return 0;
}