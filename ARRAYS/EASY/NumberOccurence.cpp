#include<iostream>
#include <map>

using namespace std;

//we will use map data structure for better time and spce comlexity
int Occurence(int arr[],int n){
    map<long long, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp ){
        if(it.second==1){
            return it.first;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
         cin>> arr[i];
    }
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }

    cout<<endl;
//by using hasing but we cant use it every time becuase if we have large number slike 10@9 or negtive numbers if=t will be diificult for us to hash
//     int hash[20]={0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }

//  for(int i=0;i<n;i++){
//     if(hash[i]==1)
//     cout<<i<<" ";
//  }


int a=Occurence(arr,n);
cout<<a<<endl;

    return 0;

}