#include<iostream>

using namespace std;

bool digit(char c){
        if(c>='0' && c<='9') return true;
        return false;
    }

int myAtoi(string s) {
       vector<int> vec;
       int flag=0;
       int sign=1;
       int flag0=0;
       int count=0;
       int flagDigitStart=0;
       bool digitStart=false;
       bool signStart=false;
       int flagSignStart=0;
       for(int i=0;i<s.size();i++){
           if(!digit(s[i]) && s[i]!=' ' && s[i]!='-' && s[i]!='+'){
               break;
           } else if(!digit(s[i]) && s[i]==' ') {
               if(signStart) flagSignStart=1;
               if(digitStart) flagDigitStart=1;
           }
            else if(digit(s[i]) && flagDigitStart==0 && flagSignStart==0){
                digitStart=true;
               int num=s[i]-'0';
               if(num==0) flag0=1;
              if(num==0 && flag==0) continue;
              else{
                  vec.push_back(num);
                  flag=1;
              }
           }
           if(s[i]=='+'){
               signStart=true;
               count++;
               if(count>1 || flag0==1 || digitStart) break;
               if(!digitStart)sign=1;
           } 
           if(s[i]=='-' ){
               signStart=true;
               count++;
               if(count>1 || flag0==1 || digitStart) break;
               if(!digitStart)sign=-1;
           }
           
       }
    long long ans=0;
       for(auto it:vec){
           ans=(ans*10)+it;
       
       if(ans*sign>=INT_MAX) return INT_MAX;
       if(ans*sign<=INT_MIN) return INT_MIN;
       }
       return ans*sign;
    }

int main(){

    return 0;
}