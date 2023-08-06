#include<iostream>

using namespace std;

//optimal appraoch by binary search 
 int minEatingSpeed(vector<int>& piles, int h) {
        //finding max element in the array
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }

        
        int low=1;
        int high =maxi;
        while(low<=high){
            int mid=(low+high)/2;
            long long hours=0;
            for(int i=0;i<n;i++){
            hours += ceil(static_cast<double>(piles[i]) / mid);
            }
            if(hours<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }

int main(){

    return 0;
}