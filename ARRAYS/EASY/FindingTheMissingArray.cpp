#include<iostream>

using namespace std;
//brute approach for this 
int Missing_number(int arr[],int n,int m){
     for(int i=1 ;i<=m;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
         if(flag==0){
                return i;
            }
     }
}


//better approach by using hash mapping
int Missing_number2(int arr[],int n,int m){
    int hash[20]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=m;i++){
     if(hash[i]==0){
        return i;
     }
    }
    
}


//optimal approach for solving the question by using XOR!! 
int Missing_number3(int arr[],int n,int m){
int xor1=0,xor2=0;
int q=n-1;
for(int i=0;i<q;i++){
    xor1=xor1^(i+1);
    xor2=xor2^arr[i];

}
xor1=xor1^n;
return xor1^xor2;

}


int main(){
     int n,m;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
 cout<<endl;
     cin>>m;

int p=Missing_number2(arr,n,m);
cout<<p<<endl;
    return 0;
}