#include<iostream>

using namespace std;

 int findingGreaterEqualTo(vector<int> &row ,int mid){
    int low=0;
    int high=row.size()-1;
    while(low<=high){
        int md=(low+high)/2;
        if(row[md]<=mid){
            low=md+1;
        } else high=md-1;
    }
    return low;
}

int median(vector<vector<int>> &mat, int m, int n) {
   

    int row=mat.size();
    int col=mat[0].size();
    int low=0;
    int high=1e9;
    while(low<=high){
        int mid= (high-low)/2+low;
        int cnt=0;
        for(int i=0;i<row;i++){
            cnt+=findingGreaterEqualTo(mat[i],mid);
        }
        
        if(cnt>(row*col)/2) high=mid-1;
        else low=mid+1;
    }
    return low;


}

int main(){

    return 0;
}