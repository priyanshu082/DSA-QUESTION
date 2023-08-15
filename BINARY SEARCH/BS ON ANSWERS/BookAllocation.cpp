#include<iostream>

using namespace std;

#include<limits.h>

int allocation(vector<int>& arr,int maxPage){
    int size=arr.size();
    int student=1;
    int totalPage=0;
    for(int i=0;i<size;i++){ 
        if(totalPage+arr[i]<=maxPage) {
            totalPage+=arr[i];
        }
        else{
            student++;
            totalPage=arr[i];
        }
    }
 return student;

}

int findPages(vector<int>& arr, int n, int m) {

    if(m>n) return -1;

    int size=arr.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<size;++i){
        sum+=arr[i];
        maxi=max(maxi,arr[i]);
    }

    if(size==1) return sum;
    int low=maxi;
    int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int stud=allocation(arr, mid);
        if(stud>m) low=mid+1;
        else high=mid-1;
        
    }
    return low;

}

int main(){

    return 0;
}