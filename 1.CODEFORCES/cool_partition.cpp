#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int findPartition(vector<int> arr , int n){
    set<int> prev,total;
    int part=0;
    for(int i=0;i<n;i++){
        total.insert(arr[i]);
        if(prev.count(arr[i])){
            prev.erase(arr[i]);
        } 
        if(prev.size()==0){
            part++;
            prev=total;
        }
    }

    return part;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i =0;i<n;i++){
            cin>> arr[i];
        }

        int ans=findPartition(arr,n);
        cout<<ans<<endl;
    }

    return 0;
}