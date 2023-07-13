#include <iostream>

using namespace std;


//optimal solution o(n)
vector<int> func(vector<int>& arr){
    int max=INT_MIN;
    vector<int> vec;
    for(int i=arr.size()-1;i>=0;i--){
      if(arr[i]>max){
        max=arr[i];
        vec.push_back(arr[i]);
      }
    }
   
    return vec;
}

int main(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
    int size =sizeof(arr)/sizeof(arr[0]);
    vector<int> vecs(arr,arr+size);
    vector<int> p=func(vecs);

     for(auto it:p){
        cout<<it<<" ";
     }

    return 0;
}