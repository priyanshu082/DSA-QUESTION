#include<iostream>
#include<limits.h>

using namespace std;


bool canWePlace(vector<int> &arr,int dist,int cows ){
    int cntCows=1, last=arr[0];
    int n=arr.size();
    for(int i=0;i<n;i++){
         if(arr[i]-last>=dist){
        cntCows++;
        last=arr[i];
    }
    }
    return (cntCows>=cows);
}


int aggressiveCows(vector<int> &arr, int cows)
{
    int n=arr.size();
    int minDist=0;
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<n;++i){
         mini=min(mini,arr[i]);
         maxi=max(maxi,arr[i]);
        }
        int low=0;
        int high=maxi-mini;
        while(low<=high){
            int mid=(low+high)/2;
            if(canWePlace(arr, mid,cows)) low=mid+1;
            else high=mid-1;
        }
        return high;
        }

int main(){
    
    return 0;
}