#include <iostream>

using namespace std;

//printng the particular element of pascal triangle
int nCr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/i+1;
    }
    return res;
} 

//printing the trianagle
class Solution {
public:

     int nCr(int n,int r){
         int x=1;
        for(int i=0;i<r;i++){
          x=x*(n-i);
          x=x/(i+1);
        }
        return x;
     }


    vector<vector<int>> generate(int numRows){
       vector<vector<int>> vec;
       int i=1;
         while(i<=numRows){
             vector<int> temp(i,0);
             for(int j=1;j<=i;j++){
               temp[j-1]=nCr(i-1,j-1);
             }
             vec.push_back(temp);
             i++;
         }
    return vec;
    }
};


int main(){

     int n;
     cin>>n;

     for(int j=1;j<=n;j++){
    int ans=1;
     cout<<ans<<" ";
     for(int i=1;i<j;i++){
        ans=ans*(j-i);
        ans=ans/(i);
        cout<<ans<<" ";
     }
     cout<<endl;
        }

    return 0;
}