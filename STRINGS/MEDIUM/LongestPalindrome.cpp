#include<iostream>

using namespace std;

string longestPalindrome(string s) {
          int n=s.size(),i=0,j=n-1,flag=0,moveFlag=0,start,end;
          while(i<j){
            if(s[i]==s[j] && flag==0){
              start=i;
              end=j;
              i++;
              j--;
              flag=1;
            } else if(s[i]==s[j] && flag==1){
                i++;
                j--;
            } else if(s[i]!=s[j] && moveFlag==0){
              start=-1;
              end=-1;
              flag=0;
              moveFlag=1;
              i++;
            } else if(s[i]!=s[j] && moveFlag==1){
               start=-1;
              end=-1;
              flag=0;
              moveFlag=0;
              j--;
            }
          }

        if(start==-1) return s.substr(0,1);
        string ans=s.substr(start,end-start+1);
        return ans;
    }


int main(){
    cout<<"pp"<<endl;
    return 0;
}