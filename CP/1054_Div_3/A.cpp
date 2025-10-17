#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int ans=0;
        int cnt0=0;
        int cnt1=0;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            arr.push_back(val);
            if(val==0) cnt0++;
            if(val==-1) cnt1++;
        }
        ans+=cnt0;
        if(cnt1%2) ans+=2;
        cout<<ans<<endl;
    }return 0;
}