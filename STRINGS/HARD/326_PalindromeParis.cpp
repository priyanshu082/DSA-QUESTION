#include<iostream>

using namespace std;


//brute force solution
class Solution {
public:

    bool check_pali(string s1,string s2){
        string s="";
        s+=(s1+s2);
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            else if(s[i]==s[j]){
                i++;
                j--;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
              if(i!=j && check_pali(words[i],words[j])){     
                  ans.push_back({i,j});
              }
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}