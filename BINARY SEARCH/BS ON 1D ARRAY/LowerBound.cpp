#include<iostream>

using namespace std;

//using binary search 
int lowerBound(vector<int> arr, int n, int x) {
  int low = 0;
  int high = n - 1;
  int mid = 0;
  while (low < high) {
    mid = (low + high) / 2;
	 if (arr[mid] == x) return mid;
    else if (x > arr[mid]) {
      low = mid + 1;
    }
    else high = mid - 1;
  }
  if(high==low){
	  if(x<arr[high]) return high;
	  else{
		  return high+1;
	  }
  }
  else if(low>high){
	  return low;
  }

}

//c++ stl method
// int lowerBound(vector<int> arr, int n, int x) {
  
//   int lb=lowerBound(arr.begin(), arr.end(), x)-arr.begin();
//   return lb;
// }


int main(){

    return 0;
}