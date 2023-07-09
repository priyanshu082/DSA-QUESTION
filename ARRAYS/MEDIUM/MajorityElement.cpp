#include<iostream>
#include <map>


using namespace std;

//brute approach 
int FindMajorElement(int arr[],int n){
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count >n/2){
            return arr[i];
        }
    }
    return false;
}

//better appproach by using map
int FindMajorElement2(int arr[],int n){
    map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    
   for(auto it : mpp){
    if(it.second > sizeof(arr)/2){
        return it.first;
    }
   }
   return -1;
}

//optimal solution for this approach  Moore's voting algorithm
int FindMajorElement3(int arr[],int n){
    int count=0;
    int el;
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            el=arr[i];
        } else if(arr[i]==el){
            count++; 
        } else count--;
    }
int count1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el) count1++;
    }
    if(count1>n/2){
        return el;
    }
    return false;
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

    int p=FindMajorElement3(arr,n);
    cout<<p;
    
    return 0;
}