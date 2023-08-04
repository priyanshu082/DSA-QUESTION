#include<iostream>

using namespace std;

//brute force solution will runnning two loops and checking for each and every integer

//optimal solution 
int floorSqrt(int n)
{
    // Write your code here.
    int low=1;
    int high=n-1;

    if(n==1) return 1;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid==n){
                ans=mid;
                break;
        } 
        
        if(mid*mid<n) {
            ans=mid;
            low=mid+1;
        }
        else if(mid*mid>n) high=mid-1;
    }

    return ans;
}
                                               

int main(){

    return 0;
}