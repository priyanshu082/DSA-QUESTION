#include<iostream>

using namespace std;

string reorganizeString(string s) {
        int h[26]={0};
        for(int i=0;i<s.size();i++){
            h[s[i]-'a']++;
        }

    char maxFreqChar;
    int maxFreq=INT_MIN;
       for(int i=0;i<26;i++){
           if(h[i]>maxFreq){
               maxFreq=h[i];
               maxFreqChar=i+'a';
           }
       }

       int index=0;
       while(maxFreq>0 && index<s.size()){
           s[index]=maxFreqChar;
           maxFreq--;
           index+=2;
       }

       if(maxFreq != 0){
           return "";
       }

        h[maxFreqChar-'a']=0;

        for(int i=0;i<26;i++){
            while(h[i]>0){
                index=index>=s.size() ? 1 : index;
                s[index]=i+'a';
                index+=2;
                h[i]--;
            }
        }
return s;
    }

int main(){

    return 0;
}