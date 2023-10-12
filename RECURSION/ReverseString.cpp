#include<iostream>

using namespace std;

void reverse(string & s){
    //initialize variables
    static int i=0;
    static int j=s.size()-1;

    //base case
    if(i>=j) return;

    //function
    swap(s[i++],s[j--]);
    reverse(s);
}

int main(){

    string s;
    cin>>s;
    reverse(s);
    cout<<s<<endl;
    return 0;
}