#include<iostream>

using namespace std;

//binary search optimal appraoch for searching divisor
int smallestDivisor(vector<int>& arr, int limit) {
        int n=arr.size();
	int ans=INT_MAX;
	int mini=INT_MAX,maxi=INT_MIN;
	for(int i=0;i<n;++i){
		mini=min(mini,arr[i]);
		maxi=max(maxi,arr[i]);
	}

	int low=1;
	int high=maxi;
	while(low<=high){
		int mid=(low+high)/2;
		int cnt=0;
		for(int i=0;i<n;++i){
			cnt+=ceil((double)arr[i]/(double)mid);
		}

		if(cnt<=limit){
			ans=mid;
			high=mid-1;
		} else low=mid+1;
	}
	return low;
    }

int main(){

    return 0;
}