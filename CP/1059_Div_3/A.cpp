#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        int maxi=0;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
            maxi=max(maxi,vec[i]);
        }
        cout<< maxi<< endl;
    }
}