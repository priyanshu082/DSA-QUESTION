#include<iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        int cnt2=INT_MAX;
        for(int i=1;i<strs.size();i++){
            int cnt1=0;
            for(int j=0;j<strs[0].length() && j < strs[i].length();j++){
                if(strs[0][j]==strs[i][j]){
                    cnt1++;
                } else {
                    break;
                }
            }
                cnt2=min(cnt2,cnt1);
        }
        string ans=strs[0].substr(0,cnt2);
        return ans;
    }

//more optimal appraoch
 string longestCommonPrefix(vector<string>& s) {
      sort(s.begin(),s.end());
      string ans="";
      int m=s[0].size(),n=s[s.size()-1].size();
      for(int i=0;i<min(m,n);i++){
          if(s[0][i]!=s[s.size()-1][i]){
              return ans;
          } else {
              ans+=s[0][i];
          }
      }
      return ans;
    }
int main(){

    return 0;
}