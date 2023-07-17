#include<iostream>

using namespace std;

//brute force solution
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int length=0;
    int n=a.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        int sum=0;
         length=0;
        for(int j=i;j<n;j++){
            if(sum+a[j]<=k){
                sum=sum+a[j];
                length++;
             maxi=max(length,maxi);
            } else if(sum+a[j]>=k){
                break;
            }
        }
    }

    return maxi;
}

//optimal solution
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left=0,right=0;
    long long sum=a[0];
    int maxi=0;
    while(right < a.size()){
          while(left<=right && sum>k){
              sum-=a[left];
              left++;
          }
          if(sum==k){
              maxi=max(maxi,right-left+1);
          }
          right++;
          if(right < a.size()) sum+=a[right];
    }
    return maxi;
}

int main(){
     
    return 0;
}