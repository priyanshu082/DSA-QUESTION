#include<iostream>

using namespace std;

//brute force solution for the solution
  bool palindrome(string s){
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string substrs=s.substr(i,j-i+1);
                if(palindrome(substrs)) cnt++;
            }
        }
        return cnt;
    }


//optimal approach for the solution
  int expand(string s,int i,int j){
        int cnt=0;
        int n=s.length();
         while(i>=0 && j<n && s[i]==s[j]){
                    cnt++;
                    i--;
                    j++;
            }
            return cnt;
    }

  int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        //for even characters
        for(int i=0;i<n;i++){
         int odd=expand(s,i,i);
         cnt=cnt+odd;
         int even=expand(s,i,i+1);
         cnt=cnt+even;
    }
    return cnt;
    }

    
int main(){
   
    return 0;
}
