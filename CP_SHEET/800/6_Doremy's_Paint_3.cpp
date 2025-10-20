#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

bool canBeGood(vector<int>& nums){
    int n=nums.size();
    if(n==2) return true;
    unordered_map<int,int> freq;
    for(int x : nums) freq[x]++;
    if(freq.size() == 1) return true; 
    if(freq.size() > 2) return false;
    auto it = freq.begin();
    int a = it->second;
    it++;
    int b = it->second;
    return abs(a-b) <= 1 ? true : false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        if(canBeGood(nums)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
       
    }
    return 0;
}
