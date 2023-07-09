#include<iostream>

using namespace std;

int consecutive_number(int arr[],int n){
    int maxi=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
            maxi=max(maxi,count);
        }else{
            count=1;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int p=consecutive_number(arr,n);

    cout<<p<<endl;

    return 0;
}
