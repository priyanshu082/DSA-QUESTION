#include<iostream>

using namespace std;

bool isPalindrome(string s) {
        int n =s.length();
        for(char &c : s){
            c=tolower(c);
        }
        int l=0;
        int h=n-1;
        while(l<h){
            if(!(s[l]>='a' && s[l]<='z') && !(s[l]>='0' && s[l]<='9')) l++;
            else if(!(s[h]>='a' && s[h]<='z') && !(s[h]>='0' && s[h]<='9')) h--;
        
            else if(s[l]==s[h]) {
                l++;
                h--;
            } else return false;
        }
        return true;
    }

int main(){

    return 0;
}