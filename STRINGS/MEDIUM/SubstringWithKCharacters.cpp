#include<iostream>
#include<unordered_set>

using namespace std;

bool checkstr(string s,int k){
    int cnt=0;
    unordered_set<char> sets;
    for(auto ch:s){
        sets.insert(ch);
    }
    if(sets.size()==k) return true;
    return false;
}

int countSubStrings(string s, int k) 
{
    int cnt=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(checkstr(s.substr(i,j-i+1), k)) cnt++;
        }
    }
    return cnt;
}

int main(){

    return 0;
}