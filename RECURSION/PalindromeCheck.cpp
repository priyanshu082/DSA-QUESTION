#include<iostream>

using namespace std;

bool check_pali(string& s,int i,int j){
    if(i>=j) return true;

    if(s[i]!=s[j]) return false;

    return check_pali(s,i+1,j-1);
}

int main(){
    string s;
    cin>>s;
    int p=check_pali(s,0,s.size()-1);
    cout<<p<<endl;
    
    return 0;
}