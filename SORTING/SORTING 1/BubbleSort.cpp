#include<iostream>

using namespace std;

void bubble_sort(int arr[],int n){
     for(int i=n-1;i>=1;i--){
        int didSwap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1; //it implies that array is already sorted so the whole fucntion will not run ,it will end when it checks for the frst time
            }
        }
        if(didSwap==0){
            break;
        }
     }
}

//time complexity for bubble sort is o(n@2),but for the best case,if array is already sorted than the inner loop can be exited by using didswap method used above for that time complexity will be O(n).and this is the best time complexity for bubble sort.

int main(){
   int n;
   cin>> n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>> arr[i];
   }

   bubble_sort(arr,n);

   for(int i=0;i<n;i++){
    cout<< arr[i]<<" ";
   }

    return 0;
}