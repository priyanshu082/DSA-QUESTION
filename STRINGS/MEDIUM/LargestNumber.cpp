#include<iostream>

using namespace std;

static bool compare( string a , string b)
    {
        return a+b>b+a;
    }

string largestNumber(vector<int>& nums) 
    {
        vector<string> snums;
        for(auto it:nums)
        {
            snums.push_back(to_string(it));
        }

        string ans="";
        sort(snums.begin(),snums.end(),compare);
        if(snums[0]=="0") return "0";
        for(auto it: snums)
        {
            ans+=it;
        }
        return ans;
    }


int main(){

    return 0;
}