#include<iostream>

using namespace std;

int lengthOfLastWord(string s) {
        int n=s.length();
        int len=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                len++;
            }
            if(s[i]==' ' && len!=0) break; 
            else continue;
        }
        return len;
    }

int main(){

    return 0;
}