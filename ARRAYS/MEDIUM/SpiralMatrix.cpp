#include<iostream>

using namespace std;

//one solution exist
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n,vector<int>(n,0));
        int num=1;
        int top=0,left=0;
        int right=n-1,bottom=n-1;
            if(n%2==0){
        while(num<=n*n){
               for(int j=left;j<=right;j++){
                vec[top][j]=num;
                num++;
            }
             top++;
            for(int j=top;j<=bottom;j++){
                vec[j][right]=num;
                num++;
                
            }
            right--;
            for(int j=right;j>=left;j--){
                vec[bottom][j]=num;
                num++;
            
            }
               bottom--;
            if(num==n*n){
                return vec;
            } else{
                for(int j=bottom;j>=top;j--){
                vec[j][left]=num;
                num++;
            }
            left++;
            }
            }
        }






            
            else if(n%2==1){
                while(num<=n*n){
   for(int j=left;j<=right;j++){
                vec[top][j]=num;
                num++;
            }
             top++;

             if(num==n*n){
                 return vec;
             }
             else{
                for(int j=top;j<=bottom;j++){
                vec[j][right]=num;
                num++;
            }
            right--;
             }
            
            
            for(int j=right;j>=left;j--){
                vec[bottom][j]=num;
                num++;
            }
               bottom--;
             
                for(int j=bottom;j>=top;j--){
                vec[j][left]=num;
                num++;
            }
            left++;
            
                }
             
            }
            
        
        return vec;
    }
};

int main(){
    
    return 0;
}