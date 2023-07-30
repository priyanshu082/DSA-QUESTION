#include<iostream>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	sort(arr,arr+n);
	   
        int low=0;
        int high=n-1;
       pair<int,int> anspair={-1,-1};

        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
               anspair.second=arr[mid];
				if(arr[mid]==x) anspair.first=arr[mid];
				else if (mid==0) anspair.first=-1;
				else anspair.first=arr[mid-1];
                high=mid-1;
            } else{
                low=mid+1;
				if(mid==n-1) anspair.first =arr[mid];
            }
        }
        return anspair;
}


int main(){

    return 0;
}