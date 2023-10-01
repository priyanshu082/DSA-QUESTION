#include<iostream>

using namespace std;

int strStr(string haystack, string needle) {
        int index=-1;
        for(int i=0;i<haystack.size();i++){
          if(index!=-1) break;
          else if(haystack[i]==needle[0]){
            index=i;
            for(int j=0;j<needle.size();j++){
              if(haystack[i+j]==needle[j]) continue;
              else{
                index=-1;
                break;
              }
            }
          } 
        }
        return index;
    }

int main(){

    return 0;
}