#include<iostream>
#include<vector>

using namespace std;

int check(vector<int>& arr,int target){
      //base case
      int mini=INT_MAX;
      if(target==0) return 0;
      if(target<0) return INT_MAX;

      for(int i=0;i<arr.size();i++){
        int ans=check(arr,target-arr[i]);
        if (ans != INT_MAX) mini=min(ans+1,mini);
      }
      return mini;
}


int main() {
    int arr[] = {1, 2, 3};  // Initialize an array.
    vector<int> a(arr, arr + sizeof(arr) / sizeof(arr[0])); // Convert the array to a vector.
    
    int target = 11;
    int ans = check(a, target);

    if (ans == INT_MAX) {
        cout << "It's not possible to make the target sum." << endl;
    } else {
        cout << "Minimum number of coins: " << ans << endl;
    }

    return 0;
}