#include<iostream>

using namespace std;

bool isIsomorphic(string s, string t) {
        int hash[256]={0};
        int isHashed[256]={0};
        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==0 && isHashed[t[i]]==0){
                hash[s[i]]=t[i];
                isHashed[t[i]]=true;
            } else {
                if(hash[s[i]]==t[i]) continue;
                return false;
            }
        }
        return true;
    }

int main(){

    return 0;
}