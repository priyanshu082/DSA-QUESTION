#include<iostream>

using namespace std;

 string removeDuplicates(string s) {
        int i=0;
       
        while(s[i+1]!='\0'){
            if(s[i]==s[i+1]){
                s.erase(i,2);
                if(i>=1) i--;
            } else {
                i++;
            }
        }
        return s;
    }

int main(){

    return 0;
}