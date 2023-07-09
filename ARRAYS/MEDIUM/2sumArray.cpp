#include<iostream>
#include <set>
#include <map>

using namespace std;


//it will just return boolean not the index that if there exist number or not whose sum is equal to the asked number
bool SumArray(int arr[]){
    
     for(int i=0;i<6;i++){
         for(int j=0;j<6;j++){
            if(i==j){

            } else if(arr[i]+arr[j]==14){
               return true;
            } 
         }
     }
     return false;
}

//this will return the index of the arrays which will give you the given sum.
vector<int> SumArray2(int arr[]){
     vector<int> set;
     for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
             if(arr[i]+arr[j]==14){
               set.push_back(arr[i]);
                set.push_back(arr[j]);
            }
        }
     }
     return set;
}

//by using map
string SumArray3(int arr[]){
    map<int,int> mpp;
    for(int i=0;i<10;i++){
       int a=arr[i];
       int more=14-a;
       if(mpp.find(more)!=mpp.end()){
        return "YES";
       }
       mpp[a]=i;
    }
   return "NO";
} 

//two pointer approach after sorting the array we will use this appraoch
string SumArray4(int arr[],int n){
    vector<int> vec;
    int i=0,j=n-1;
   while(i<j){
   if(arr[i]+arr[j]< 14){
    i++;
   } else if(arr[i]+arr[j]>14){
    j--;
   } else if(arr[i]+arr[j]==14){
    return "YES";
   } 
   }
   return "NO";
   }


int main(){
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
string p=SumArray4(arr,n);
   
   cout<<p<<endl;  
    return 0;
}