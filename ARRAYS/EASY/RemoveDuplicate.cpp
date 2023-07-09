#include<iostream>
#include<set>

using namespace std;

int Remove_duplicate(int arr[],int n){
    set<int> set;
    for(int i=0;i<n;i++){
        set.insert(arr[i]);
    }
    int index=0;
    for(auto it:set){
        arr[index]=it;
        index++;
    }
}


int main(){
      //remove duplicate from array
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

   set<int> set;
    for(int i=0;i<n;i++){
        set.insert(arr[i]);
    }
    int index=0;
    for(auto it:set){
        arr[index]=it;
        index++;
    }

   for(int i=0;i<set.size();i++){
     cout<<arr[i]<<" ";
    }
    
    return 0;
    
}