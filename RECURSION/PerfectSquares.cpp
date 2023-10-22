#include<iostream>

using namespace std;

class Solution {
public:

  int check(int n){
      if(n==0) return 1 ;
      if(n<0) return 0;
      int i=1;
      int end=sqrt(n);
      int ans=INT_MAX;

      while(i<=end){
          int square=i*i;
          int cnt=1+check(n-square);
          ans=min(ans,cnt);
          ++i; 
      }
      
      return ans;
   }

    int numSquares(int n) {
       return check(n)-1;
    }
};

int main(){
    return 0;
}