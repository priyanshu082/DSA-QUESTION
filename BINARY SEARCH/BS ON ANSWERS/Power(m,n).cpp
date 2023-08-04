#include<iostream>

using namespace std;

//binary search 
int NthRoot(int m, int n) {
  // Write your code here.
    int low=1;
    int high=n;

    if(n==1) return 1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        long long p=1;
        int val;

        for(int i=1;i<=m;i++){
             p*=mid;
             if(p>n){
              val=2;
              break;
             } 
             if(p==n) val=1;
             else val=0;
        }
         if(val==1){
                 ans=mid;
                 break;
         } 
        
       else if(val==0) {
            low=mid+1;
        }

        else if(val==2) high=mid-1;
    }

    return ans;
}


int main(){

    return 0;
}