//longest sub arry with sum equal to k

#include<iostream>

using namespace std;

//brute approach for soling the question
int SubArray(int arr[],int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            for(int k=i;k<j;k++){
                sum+=arr[k];
            }
        }
    }
}

int main(){

    return 0;
}