#include<iostream>

using namespace std;

//binary search and lower and upper bound concepts can also be used but this done by different approach
int count(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n - 1;
    int i=-1;
	int j=-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
             i = mid;
             j = mid;
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
            while (j > 0 && nums[j - 1] == nums[j]) j--;
			break;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
	if(i==-1 && j==-1) return 0;
 int ans=i-j+1;
    return ans;

	}

int main(){

    return 0;
}