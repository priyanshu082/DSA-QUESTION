#include<iostream>

using namespace std;

//time complexity is very low  but occupies space
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        string ans="";
        int i=0;
        int j=0;
        while(i<=s.length()){
            if(ans.length()<n){
                if(s[i]=='\0') break;
                ans.push_back(s[i]);
                i++;
                j++;
            } else if(ans.substr(j-n,n)==part){
               for(int p=0;p<n;p++){
                   ans.pop_back();
                   j--;
               }
               if(s[i]=='\0') break;
            } else{
                if(s[i]=='\0') break;
                ans.push_back(s[i]);
                i++;
                j++;
            } 
        }
        return ans;
    }
};

//short and refined code but uses extra time and have space complxity 1;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<=s.length()) {
            s.erase(s.find(part),part.length());
        }
         return s;
    }
   
};

int main(){



    return 0;
}