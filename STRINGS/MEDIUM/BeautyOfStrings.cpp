#include<iostream>

using namespace std;

//brute force soltuion
 int checkBeauty(string s){
        int hash[26]={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
        }
        int max=INT_MIN,min=INT_MAX;
       
        for(int i=0;i<26;i++){
            
            if(hash[i]>max){
                max=hash[i];
            } if(hash[i]!=0 && hash[i]<min){
                min=hash[i];
            }
        }
     return (max-min);
       
    }

    int beautySum(string s) {
        int cnt=0;
          for(int i=0;i<s.size();i++){
              for(int j=1;j<=s.size()-i;j++){
                   cnt+=checkBeauty(s.substr(i,j));
              }
          }
          return cnt;
    }


//optimal appraoch for the solution
int beautySum(string s) {
        int cnt=0;
          for(int i=0;i<s.size();i++){
              unordered_map<char,int> mpp;
              for(int j=i;j<s.size();j++){
                  mpp[s[j]]++;
                  int maxi=INT_MIN, mini=INT_MAX;
                  for(auto it:mpp){
                      maxi=max(maxi,it.second);
                      mini=min(mini,it.second);
                  }
                  cnt+=(maxi-mini);
              }
          }
          return cnt;
    }


int main(){

    return 0;
}