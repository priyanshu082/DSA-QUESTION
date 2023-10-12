#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       int maxlen=0;
       vector<int> index(256,-1);
       int start=0;
       for(int i=0;i<n;++i){
           if(index[s[i]]!=-1){
               start=max(start,index[s[i]]+1);
           }

           index[s[i]]=i;
           maxlen=max(maxlen,i-start+1);
       }
       return maxlen;
    }
};

int main(){

    return 0;
}