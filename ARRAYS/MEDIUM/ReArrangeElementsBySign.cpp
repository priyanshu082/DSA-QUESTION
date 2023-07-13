#include <iostream>

using namespace std;

//brute approach by placing them in different arrays and again placing them to original array
//1st approach time complexity o(n) and space complexity o(n) but here unabale to solve .....in o(n) but when we use vector and pass array in that function we will be able to solve in o(n)
int func(int arr[]){
    int n=sizeof(arr);
    int k=0,q=1;
    vector<int> newArr(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            newArr[q]=arr[i];
            q=q+2;
        } else if(arr[i]>0){
            newArr[k]=arr[i];
            k=k+2;
        }
    }
   
    return arr[n];
}

//
int func2(int arr[]){
    
}

int main(){
    // int arr[6]={3,1,-2,-5,2,-4};
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
    int p=func(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}