#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        bool change=true;
        while(change){
            change=false;
            for(int i=1;i<n-1;i++){
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                    swap(nums[i],nums[i+1]);
                    change=true;
                }
            }
        }
        if(is_sorted(nums.begin(),nums.end())) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
       
    }
    return 0;
}
