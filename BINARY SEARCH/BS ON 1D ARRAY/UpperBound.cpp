#include<iostream>
using namespace std;

// upper bound is as same as lower bound
int upperBound(vector<int> &arr, int x, int n){
		  int low = 0;
  int high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] > x) {
      ans=mid;
      high=mid-1;
    }
     else {
      low =mid + 1;
    } 
  }
 return ans;
}


int main(){

    return 0;
}