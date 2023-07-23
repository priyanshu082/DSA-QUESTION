#include<iostream>
#include<map>

using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	map<int,int> mpp;
	int n=arr.size();
	int maxi=0;
	int sum=0;
	for(int i=0;i<n;i++){
		 sum+=arr[i];
		if(sum==0){
			maxi=i+1;
		} else{
			 if(mpp.find(sum)!=mpp.end()){
			maxi=max(maxi,(i-mpp[sum]));
		} else{
			mpp[sum]=i;
		}
		
		}
		
	}
	return maxi;
}



int main(){

    return 0;
}