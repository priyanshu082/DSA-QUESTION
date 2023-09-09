#include<iostream>

using namespace std;

class Solution {
public:
    bool checkPalindrom(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            } else return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<=j){
            int flag=0;
          if(s[i]!=s[j]){
              return checkPalindrom(s,i+1,j) || checkPalindrom(s,i,j-1);
          } else if(s[i]==s[j]){
                i++;
                j--;
            }
        }
        return true;
    }
};


int main(){

    return 0;
}