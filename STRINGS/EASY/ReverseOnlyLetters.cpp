#include<iostream>

using namespace std;

   string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) && ((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z')) ) {
                swap(s[i],s[j]);
                i++;
                j--;
            } else if(!((s[i]>='a' && s[i]-'z'<=26) || (s[i]>='A' && s[i]<='Z'))){
                i++;
            } else if(!((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))){
                j--;
            }
        }
        return s;
    }

int main(){

    return 0;
}