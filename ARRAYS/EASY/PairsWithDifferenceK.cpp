#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int counter=0;
        for(int i=0;i<nums.size();i++){
            int num1=nums[i]-k; 
            int num2=nums[i]+k; 

            if(mpp.find(num1)!=mpp.end()){
                counter+=mpp[num1];
            }

             if(mpp.find(num2)!=mpp.end()){
                counter+=mpp[num2];
            }

            mpp[nums[i]]++;
        }
        return counter;
    }
};

int main(){

    return 0;
}