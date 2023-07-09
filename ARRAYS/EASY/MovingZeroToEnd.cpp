#include<iostream>
#include<vector>

using namespace std;

void moving_zero(int arr[],int n){
    vector<int> temp;
    int p=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
        else{
           p++ ;
        }
    }
    
    for(int i=0;i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++){
        arr[i]=0;
    }
}

//optimal approach for solving the question
//we will use 2 pointer appraoch here for solving the question

void moving_zero2(int arr[],int n){
int j=-1;
for(int i=0;i<n;i++){
    if(arr[i]==0){
    j=i;
    break;
    }
}

if(j==-1) return;

for(int i=j;i<n;i++){
    if(arr[i]!=0){
     swap(arr[i],arr[j]);
     j++;
    }
}
}


int main(){
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

     moving_zero2(arr,n);

     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }


    return 0;
}
