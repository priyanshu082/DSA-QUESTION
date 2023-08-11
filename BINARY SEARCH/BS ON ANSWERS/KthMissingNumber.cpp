#include<iostream>

using namespace std;

//using binary 
  int findKthPositive(vector<int>& arr, int k){
        int n=arr.size(); 
        int low=0;
        int high=n-1;
    
        while(low<=high){
           int  mid=(low+high)/2;
            int missing =arr[mid]-(mid+1);
            if(missing<k)low=mid+1;
            else high=mid-1;
        }
        return k+high+1;
    }

int main(){

    return 0;
}