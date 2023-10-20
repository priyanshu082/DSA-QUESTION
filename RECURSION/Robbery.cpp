#include<iostream>

using namespace std;

class Solution {
public:

int robbery(vector<int> &nums,int i)
{
     if(i>=nums.size()){
         return 0;
     }
       
        int amt1=nums[i]+robbery(nums,i+2);
        int amt2=robbery(nums,i+1);

        return max(amt1,amt2);
}

    int rob(vector<int>& nums) 
    {
       return robbery(nums,0);
    }
};

int main(){

    return 0;
}