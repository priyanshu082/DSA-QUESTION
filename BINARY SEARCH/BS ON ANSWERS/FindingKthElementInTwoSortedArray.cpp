#include<iostream>

using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
       
       int i=0,j=0;
       int cnt=0;
       int ans;
       
       
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
              cnt++;
              if (cnt == k) {
              ans = arr1[i];
                break;
              }
              i++;
            } else{
                cnt++;
                if(cnt==k) {
                    ans=arr2[j];
                    break;
                }
                j++;
            }
        }

        while(i<n){
              cnt++;
              if (cnt == k) {
              ans = arr1[i];
                break;
              }
              i++;
        }

        while(j<m){
                cnt++;
             if(cnt==k) {
                    ans=arr2[j];
                    break;
                }
                j++;
        }
        return ans;
}

int main(){

    return 0;
}