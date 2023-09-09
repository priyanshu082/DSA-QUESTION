#include<iostream>

using namespace std;

//optimal time soltuion
 string removeDuplicates(string s) {
       string ans="";
       for(int i=0;i<s.length();i++){
           if(ans.length()!=0 && ans[ans.length()-1]==s[i]){
               ans.pop_back();
           } else{
               ans.push_back(s[i]);
           }
       }
       return ans;
    }

//optimal time and optimal space solution
    class Solution {
public:
    string removeDuplicates(string s) {
       string ans="";
       for(int i=0;i<s.length();i++){
           if(ans.length()!=0 && ans[ans.length()-1]==s[i]){
               ans.pop_back();
           } else{
               ans.push_back(s[i]);
           }
       }
       return ans;
    }
};

int main(){

    return 0;
}