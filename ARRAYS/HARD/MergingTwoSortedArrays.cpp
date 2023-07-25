#include<iostream>

using namespace std;

//brute approach would be doing iteration of each and every array and stroting into the third vector

//optimal -1
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
        int n=a.size();
	 int m=b.size();
		int left =n-1;
		int right=0;
	while(left>=0 && right<m){
        if(a[left]>b[right]){
			swap(a[left],b[right]);
			left--,right++;
		} else {
			break;
		}
	}
    sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}
	

int main(){

    return 0;
}