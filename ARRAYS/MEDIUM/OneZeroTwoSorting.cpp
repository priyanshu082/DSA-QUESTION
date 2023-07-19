#include <iostream>
#include <vector>

using namespace std;


int* Sorting(int arr[],int n){
       int zeros=0;
       int ones=0;
       int twos=0;
       for(int i=0;i<n;i++){
        if(arr[i]==0) zeros++;
        else if(arr[i]==1) ones++;
        else twos++;
       }

       for(int i=0;i<zeros;i++){
        arr[i]=0;
       }
       for(int i=zeros;i<zeros+ones;i++){
        arr[i]=1;
       }
       for(int i=ones+zeros;i<n;i++){
        arr[i]=2;
       }
       return arr;
 }

//dutch national flag algorithm
int* Sorting2(int arr[],int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        } else if(arr[mid]==1){
            mid++;
        } else{
            swap(arr[high],arr[mid]);
            high--;
            
        }
    }
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

    int* p=Sorting(arr,n);
    
    for(int i=0;i<n;i++){
       cout<< p[i]<<" ";
    }


    return 0;
 }