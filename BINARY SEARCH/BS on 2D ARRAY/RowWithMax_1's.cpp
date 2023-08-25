#include<iostream>

using namespace std;

int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
{
    //    Write your code here.
    int ans=-1;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt++;
               if(cnt>maxi){
                   ans=i;
                   maxi=cnt;
               } 
            if(cnt==m) return i;
            }
            
        }
    }
    return ans;
}

//better time complexity and used lowerbound
int lowerBound(vector<int> &arr,int m,int x){
        int low=0;
        int high=m-1;
        int ans=m;
         if(arr[0]==x) return 0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int cnt=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m-lowerBound(matrix[i], m, 1);
        if (cnt_ones==m) return i;
        if(cnt_ones>cnt){
            cnt=cnt_ones;
            index=i;
        }
        
    }
    return index;
}


int main(){

    return 0;
}