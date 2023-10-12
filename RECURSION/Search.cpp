#include<iostream>

using namespace std;

int check(string& s,char target ,int& ans){
    static int i=0;
    if(i>=s.size()) return ans;

    if(s[i]==target) {
        ans=i;
    };
    i++;
    check(s,target,ans);
}

int main(){
    string s ;
    cin>>s;
    char ch;
    cin>>ch;
    int ans=-1;
    check(s,ch,ans);
    cout<<ans<<endl;
}