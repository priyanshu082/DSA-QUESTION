#include<iostream>

using namespace std;

     
     int arraySpliter(vector<int>& arr,int capacity){
        int n=arr.size();
        int sum=0;
        int num=1;
        int maximum=INT_MIN;
        for(int i=0;i<n;++i){
            if(sum+arr[i]<=capacity){
                sum+=arr[i];
            } else {
                num++;
                sum=arr[i];
            }
        }
        return num;
    }
int largestSubarraySumMinimized(vector<int> arr, int k) {

    
        int n=arr.size();
        if(k>n) return -1;

        int sum=0;
        int maxi=INT_MIN;

        for(int i=0;i<n;++i){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        

        if(k==n) return maxi;
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int result = arraySpliter(arr,mid);
             if(result>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    } 


int main(){

    return 0;
}