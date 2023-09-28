#include<iostream>
#include<map>
#include<vector>

using namespace std;

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string ,vector<string>> mpp;
       for(auto it :strs){
           string s=it;
           sort(s.begin(),s.end());
           mpp[s].push_back(it);
       }

        vector<vector<string>> ans;
    for (auto it = mpp.begin(); it != mpp.end(); it++) {
    ans.push_back(it->second);
}



       return ans;
    }

int main(){

    return 0;
}