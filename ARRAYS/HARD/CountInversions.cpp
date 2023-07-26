#include<iostream>

using namespace std;

//brute force will be running two loops and finding the small element on the left for each element and returning the count
int numberOfInversions(vector<int>&a, int n) {
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) cnt++;
        }
    }
    return cnt;
}


//optimal appraoch
int sorting(int arr[],int low,int mid,int high){
    vector<int> temp;
    int cnt=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
cnt++;
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
    return cnt;
}

int merge_sort(int arr[],int low, int high){
    int cnt=0;
    if(low==high) return cnt;
    int mid=(low+high)/2;
    cnt+=merge_sort(arr,low,mid);
    cnt+=merge_sort(arr,mid+1,high);
    cnt+=sorting(arr,low,mid,high);
    return cnt;
}


int main(){

    return 0;
}