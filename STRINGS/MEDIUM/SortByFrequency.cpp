#include<iostream>
#include<map>

using namespace std;

static bool cmp(const pair<char,int>&a,const pair<char,int>&b ){
         return a.second>b.second;
     }

string frequencySort(string s) {
      map<char,int> mpp;
      for(auto ch:s) mpp[ch]++;
      vector<pair<int,int>> res;
      for(auto it :mpp) res.push_back(it);
      sort(res.begin(),res.end(),cmp);

      string ans="";
      for(auto it:res) {
          int temp=it.second;
          while(temp--){
              ans+=it.first;
          }
      }
      return ans;
    }

int main(){

    return 0;
}