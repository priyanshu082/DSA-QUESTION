#include<iostream>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        int mini=INT_MAX;
        while(n>0){
            mini=min(mini,n%10);
            n/=10;
        }
        cout<<mini<<endl;
    }
}