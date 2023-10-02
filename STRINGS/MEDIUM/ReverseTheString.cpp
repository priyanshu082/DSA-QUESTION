#include<iostream>

using namespace std;

string reverseWords(string s) {
        int i=s.size()-1;
        string ans="";
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            string res="";
        
            while( i>=0 && s[i]!=' ' ){
                res+=s[i];
                i--;
                
            }
            
            if(res.size()!=0) {
            for(int j=res.size()-1;j>=0;j--){
             ans+=res[j];
            }
            ans+=' ';
            }
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }


int main(){


    return 0;
}