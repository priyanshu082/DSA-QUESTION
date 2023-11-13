#include<iostream>

using namespace std;

void solve(vector<string> &ans,int open,int close,string output){
    //base case
    if(open==0 && close==0){
        ans.push_back(output);
        return;
    }

    //open insert krte hue
    if(open>0){
        output.push_back('(');
        solve(ans,open-1,close,output);
        output.pop_back();
    }

    //inserting close
    if(close>open){
        output.push_back(')');

        solve(ans,open,close-1,output);
        output.pop_back();
    }
}

int main(){
    int n=2;
    vector<string> ans;
    string output="";
    solve(ans,n,n,output);
    for(string it:ans){
        cout<<it<<" ";
    }

    return 0;
}