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
	
//optimal-2 gap method.....shell sort
void SwapGreater(vector<long long>& arr1, vector<long long>& arr2, int ind1, int ind2) {
  if (arr1[ind1] > arr2[ind2]) {
    swap(arr1[ind1], arr2[ind2]);
  }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a,
                                           vector<long long> &b) {
  int n = a.size();
  int m = b.size();
  int len = m + n;
  int gap = (len / 2) + (len % 2);
  while (gap > 0) {
    int left = 0;
    int right = left + gap;
    while (right < len) {
      // arr1 and arr2
      if (left < n && right >= n) {
		  SwapGreater( a,  b, left, right-n);
      }
	  //arr2 and arr2
     else if (left >=n) {
		  SwapGreater (a,  b, left-n, right-n);
      }
	  //arr1 and arr1
      else {
		  SwapGreater (a, b, left, right);
      }
	  right++,left++;
    }
	if(gap==1) break;
	gap=(gap/2)+(gap%2);
  }
}


int main(){

    return 0;
}