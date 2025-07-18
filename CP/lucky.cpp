// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int findLucky(int l,int r){
    
    int num=l;
    int prevMax=INT_MIN;
    for(int i=l;i<=min(r,l+100);i++){
        int j=i;
        int maxi=-1;
        int mini=10;
        
        while(j>0){
            int temp=j%10;
            j/=10;
            if(temp>maxi) maxi=temp;
            if(temp<mini) mini=temp;
        }

        if((maxi-mini)>prevMax){
            num=i;
            prevMax=maxi-mini;
        }
        if(prevMax==9) break;
    }
    return num;
}

int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int l,r;
        cin>>l>>r;
        int ans=findLucky( l, r);
        cout<<ans<<endl;
    }

    return 0;
}