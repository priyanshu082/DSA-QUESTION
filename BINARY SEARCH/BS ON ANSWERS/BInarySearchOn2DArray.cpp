#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){

    int row,col;
    int operation=1;
    cout<<"Enter the row size"<<endl;
    cin>>row;
    cout<<"Enter the column size"<<endl;
    cin>>col;

    int arr[row][col];

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            arr[i][j]=(10*i)+rand()%10;
        }
        cout<<endl;
    }

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int q=0;q<row;++q){
        for(int i=0;i<col;++i){
            for(int j=0;j<col-i-1;++j){
                    if(arr[q][j]>arr[q][j+1]){
                        int temp=arr[q][j+1];
                        arr[q][j+1]=arr[q][j];
                        arr[q][j]=temp;
                }
            }
        }
    }

     for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
                cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Please enter the target you want to search for"<<endl;
    int target;
    cin>>target;
     int ans=-1;
     int low;
     int high;

     int mid;
     int ansRow;

     int rlow=0;
     int rhigh=row-1;
     int rmid;

     while(rlow<=rhigh){
        rmid=(rlow+rhigh)/2;
        low=0;
        high=col-1;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[rmid][mid]==target){
                ans=arr[rmid][mid];
                break;
            }
            else if(arr[rmid][mid]>target) high=mid-1;
            else low=mid+1;
            operation++;
        }
        if(ans==target) break;
        else if(target<arr[rmid][0]) rhigh=rmid-1;
        else if(target>arr[rmid][col-1]) rlow=rmid+1;
     }

     if(ans==target){
        cout<<"Search is succesful "<<target<< " is present in the matrix"<<endl;
        cout<<"It is present at "<<rmid<<" "<<mid<<" position in matrix"<<endl;
        cout<<"NO.of operations in searching the row and column is == "<<operation<<endl;
     } else{
        cout<<"Search is unsuccessfull"<<endl;
     }



    return 0;
}