#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
        vector<vector<int>> ans;
void r(int k , int remSum,int i , vector<int> temp){
    if(remSum==0 && temp.size()==k){
        ans.push_back(temp);
        return ;
    }

    if(temp.size()>k  || remSum<0 || i>9) return ;

   for(int j=i;j<=9;j++){
     if(j>remSum) continue;
    temp.push_back(j);
    r(k,remSum-j,j+1,temp);
    temp.pop_back();

   }


}
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> temp;
        r(k,n,1,temp); 

        return ans;
    }
};

 int main(){

    return 0;
 }