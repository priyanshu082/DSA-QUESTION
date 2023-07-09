#include<iostream>

using namespace std;

int second_largest(int arr[],int n ){
int largest=arr[0];
int slargest=-1;
for(int i=1;i<n;i++){
    if(arr[i]>largest){
     slargest=largest;
     largest=arr[i];
    }else if(arr[i]<largest && arr[i]>slargest){
        slargest=arr[i];
    }
}
return slargest;
}

int second_smallest(int arr[],int n){
    int smallest=arr[0];
    int Ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            Ssmallest=smallest;
            smallest=arr[i];
        }else if(arr[i]>smallest && arr[i]< Ssmallest){
            Ssmallest=arr[i];
        }
    }
    return Ssmallest;
}

int main(){

    int n;
    cin>> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>> arr[i];
    }
    for (int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout <<endl;
     
     cout<< second_largest(arr,n)<<endl;
     cout<<second_smallest(arr,n)<<endl;


    return 0;
}