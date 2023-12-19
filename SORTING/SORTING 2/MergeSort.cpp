#include<iostream>

using namespace std;

void sorting(int arr[],int low,int mid,int high){
    vector<int> temp;
    int left=low, right=mid+1;  //right=mid+1 implements that left is on left array and right is on right array
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }  
    while(left<=mid) temp.push_back(arr[left++]); //entering the remaining data of left 
      
    while(right<=high) temp.push_back(arr[right++]); //entering the remaining data of right 
       
    for(int i=low;i<=high;i++) arr[i]=temp[i-low]; //copying the sorted data from temp to array
}


void merge_sort(int arr[],int low, int high){
    if(low==high) return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);  //breaking the array into two groups
    merge_sort(arr,mid+1,high);
    sorting(arr,low,mid,high); // merging nd sorting the array
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}