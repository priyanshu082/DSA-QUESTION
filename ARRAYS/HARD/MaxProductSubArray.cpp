#include<iostream>

using namespace std;

#include<vector>

//brute force appraoch 
int subarrayWithMaxProduct(vector<int> &arr){
	
	int n=arr.size();
	int maxi=arr[0];
	for(int i=0;i<n;i++){
		int product=arr[i];
		for(int j=i+1;j<n;j++){
		      product=product*arr[j];
		}
		maxi=max(maxi,product);
	}
	return maxi;
}


//optimal
int subarrayWithMaxProduct(vector<int> &arr){
    int pre=1;
    int n=arr.size();
    int suf=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suf==0) suf=1;
        suf=suf*arr[n-i-1];
        pre=pre*arr[i];
        ans=max(ans,max(suf,pre));

    }
    return ans;
}



int main(){

    return 0;
}