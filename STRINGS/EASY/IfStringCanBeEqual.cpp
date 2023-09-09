#include<iostream>

using namespace std;

bool canBeEqual(string s1, string s2) {
        int cnt=0;
        int i=0;
        while(s1!=s2){
       if(s1[i]!=s2[i]){
          swap(s1[i],s1[i+2]);
          i++;
          cnt++;
      } else {
          i++;
      }
      
      if(s1!=s2 && cnt>=2) return false; 
        }

    return true;
    }

int main(){

    return 0;
}