#include<iostream>

using namespace std;

int max_ele(int arr[],int n,int index,int& maxi){
  // static int index=0;
  // static int maxi=-1;
      if(index>=n) return maxi;
      if(arr[index]>maxi){
        maxi=arr[index];
      }
      index++;
    return max_ele( arr, n,index,maxi);
}

int main(){

  int arr[5]={3,6,9,5,2};
  int index=0;
  int maxi=-1;
  max_ele(arr,5,index,maxi);

  cout<<maxi<<endl;

  return 0;
}