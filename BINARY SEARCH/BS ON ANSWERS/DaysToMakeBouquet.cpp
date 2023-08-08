#include<iostream>

using namespace std;

//binary search optimal approach
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();

        if((long long)m*k>n) return -1;
        int ans=0;
        int mini=INT_MAX;
        int maxi=INT_MIN; 
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]); 
        }

        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=0;
            int noOb=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                   cnt++;
                }
                else { 
                    noOb+=(cnt/k);
                    cnt=0;
                    }
            }
            noOb+=(cnt/k);
            if(noOb>=m) high=mid-1; 
            else low=mid+1;
        }
       return low;
    }
};

int main(){

    return 0;
}