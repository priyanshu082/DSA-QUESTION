#include<iostream>

using namespace std;

bool digit(char c){
        if(c>='0' && c<='9') return true;
        return false;
    }

int myAtoi(string s) {
       
       long long ans=0;
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
                  ans=(ans*10)+num;
                  if(ans*sign>=INT_MAX) return INT_MAX;
                  if(ans*sign<=INT_MIN) return INT_MIN;
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

       return ans*sign;
    }


//optimised code
 int myAtoi(string s) {
     long long num=0,i=0,sign=1;

     while(s[i]==' '){
         i++;
     }

     if(i<s.size() && (s[i]=='-' || s[i]=='+')){
         sign=s[i]=='+' ? 1 : -1;
         ++i;
     }

     while(i<s.size() && isdigit(s[i])){
         num=num*10+(s[i]-'0');
         if(num*sign>INT_MAX) return INT_MAX;
         if(num*sign<INT_MIN) return INT_MIN;
         ++i; 
     }

    return num*sign;
    }


int main(){

    return 0;
}