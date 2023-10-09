#include<iostream>

using namespace std;

string removeOuterParentheses(string s) {
        int bracOpen=0;
      
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' ){
               if(bracOpen>0) ans+=s[i];
                bracOpen++;
            } else if(s[i]==')'){
                bracOpen--;
                if(bracOpen>0){ 
                   ans+=s[i];
                }
            }
        }
        return ans;
    }

int main(){

    return 0;
}