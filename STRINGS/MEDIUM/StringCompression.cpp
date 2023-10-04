#include<iostream>

using namespace std;

int compress(vector<char>& chars) {
        if(chars.size()==1) return chars.size();
        int i=0;
        int j=0;
        while(i<chars.size()){
            int num=0;
            char ch=chars[i];
            while(i<chars.size() && chars[i]==ch){
                num++;
                i++;
            }
            
            chars[j++]=ch;

            if(num>1){
                string str=to_string(num);
                for(auto digit:str){
                    chars[j++]=digit;   
                }
            }
        }
       
        return j;
    }

int main(){

    return 0;
}