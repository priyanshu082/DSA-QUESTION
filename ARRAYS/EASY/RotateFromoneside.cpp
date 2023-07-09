#include<iostream>
using namespace std;


//with using new arrays
void rotating_array(int arr[],int n){
int arrNew[n];
    for(int i=0;i<n;i++){
        if(i+1<n){
            arrNew[i]=arr[i+1];
        }
    }
    arrNew[n-1]=arr[0];

    for(int i=0;i<n;i++){
        arr[i]=arrNew[i];
    }

}
//without using new array
void rotating_array2(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

void rotating_array3(int arr[],int n ,int d){
    int i=0;
    while(i<(d%n)){
        int temp=arr[0];
        for(int j=1;j<n;j++){
            arr[j-1]=arr[j];
        }
        arr[n-1]=temp;
        i++;
    }
}
void rotating_array4(int arr[],int n,int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
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
    cout <<endl;
    int d;
    
    cout<<"Enter the number of times You want to rotate the array:-";
    cin>>d;

    // rotating_array(arr,n);
    rotating_array4(arr,n,d);

 for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }


    return 0;
}