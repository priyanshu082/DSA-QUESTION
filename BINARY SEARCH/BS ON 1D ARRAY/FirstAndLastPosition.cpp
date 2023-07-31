#include<iostream>

using namespace std;

//binary algo with tc=logn;
pair<int, int> firstAndLastPosition(vector<int>& nums, int n, int target)
{
    // Write your code here
    
    
    int low = 0;
    int high = n - 1;
    pair<int,int> vec = {-1, -1};

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int i = mid;
            int j = mid;
            while (i < n - 1 && nums[i + 1] == nums[i]) i++;
            while (j > 0 && nums[j - 1] == nums[j]) j--;
            vec.first = j;
            vec.second = i;
            break;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return vec;
}

int main(){

    return 0;
}