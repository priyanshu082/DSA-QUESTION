#include<iostream>

using namespace std;

 string replaceDigits(string s) {
       
        for(int i=1;i<s.size();i+=2){
                int num=s[i]-'0';
                s[i]=s[i-1]+num;  
        }
        return s;
    }

int main(){
    return 0;
}