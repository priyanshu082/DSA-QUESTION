#include<iostream>

using namespace std;

void permutation(string &s,int i){
    if(i>=s.size()){
        cout<<s<<" ";
        return ;
    }

    for(int j=i;j<s.size();j++){
         swap(s[j],s[i]);
         permutation(s,i+1);
         swap(s[j],s[i]);
    }
}

int main(){
    string s;
    cin>>s;

    permutation(s,0);

    return 0;
}