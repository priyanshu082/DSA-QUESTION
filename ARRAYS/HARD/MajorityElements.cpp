#include <iostream>

using namespace std;

//better approach would be hasing them and then chekcing if they are >n/3 or not frst put the  in rdered map and after that if key >n/3 put them in another vector and return the vector 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec;
        int mini=int(n/3)+1;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
           mpp[nums[i]]++;
           if(mpp[nums[i]] == mini) {
               vec.push_back(nums[i]);
           }
           if(vec.size()==2) return vec;
        }
        return vec;
    }
};

//optimal approach would be subtraction method in which we use less space tc will be o(2n);
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1,el2;
        int n=nums.size();
        int p=floor(n/3)+1;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            } else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            } else if(el1==nums[i]){
                 cnt1++;
            } else if(el2==nums[i]){
                cnt2++;
            } else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
        if(cnt1>=p) ls.push_back(el1);
        if(cnt2>=p) ls.push_back(el2);

        return ls;
    }
};



int main(){
    int n=4;
    int p=(6/3)+1;
    cout<<p;
    return 0;
}