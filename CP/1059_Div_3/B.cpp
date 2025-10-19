#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0;
        int r=n-1;
        vector<int> pos;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }else if(s[l]=='0'){
                pos.push_back(l);
                l++;
            }else if(s[r]=='1'){
                pos.push_back(r);
                r--;
            }else {
                l++;
                r--;
            }
        }
        cout<<pos.size()<<endl;
        for(int i=0;i<pos.size();i++){
            cout<<pos[i]<<" ";
        }
        cout<<endl;
    }
   
}