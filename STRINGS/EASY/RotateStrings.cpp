#include<iostream>

using namespace std;

bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        else{
            int flag=0;
            s+=s;
            int i=0;
            int j=-1;
            while(i<s.size()){
                if(s[i]==goal[j+1]){
                    i++;
                    j++;
                    flag=1;
                    if(j==goal.size()-1) return true;
                } else {
                    if(flag==0) i++;
                    flag=0;
                    j=0;
                }
            }
        }
        return false;
    }


//optimised code

bool rotateString(string s, string goal) {
       int n=s.size();
       char ch;
       int flag=0;
       for(int i=0;i<n;i++){
           ch=s[0];
           s.erase(0,1);
           s.push_back(ch);
           if(s==goal){
               return true;
           }
       }
       return false;
    }
int main(){

    return 0;
}