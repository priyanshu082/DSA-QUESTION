#include<iostream>

using namespace std;

//binary search 
int func(vector<int> &arr,int cap){
    int n=arr.size();
    int load=0;
    int days=1;
    for(int i=0;i<n;i++){
        if(arr[i]+load>cap){
            days++;
            load=arr[i];
        } else load+=arr[i];
    }
    return days;
}

    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0;
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;++i){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int NoOfdays=func(arr,mid);
            if(NoOfdays<=days) {
                high=mid-1;
            } else low=mid+1;
        }
        return low;
    }

int main(){

    return 0;
}