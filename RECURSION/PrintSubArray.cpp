#include<iostream>

using namespace std;

void printSubstr(string &s,int start,int end){
    if(start==s.size() && end==s.size()+1) return;
    cout<<s.substr(start,end-start)<<endl;
    if(end==s.size()) printSubstr(s,start+1,start+2);
    else printSubstr(s,start,end+1);
}

int main(){

    string s;
    cin>> s;
    printSubstr(s,0,1);
    return 0;
}