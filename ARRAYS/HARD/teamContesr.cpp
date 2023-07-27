#include<iostream>
using namespace std;


int sorting(vector<int>& skill,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> vec;
    int cnt=0;
    while(left<=mid && right<=high){
       
        if(skill[left]<=skill[right]){
            vec.push_back(skill[left]);
            left++;
        } else{
            vec.push_back(skill[right]);
            if(skill[left]>2*skill[right]) cnt+=(mid-left+1);
            right++;
            
        }
    }

    while(left<=mid){
        vec.push_back(skill[left]);
        left++;
    }
    while(right<=high){
        vec.push_back(skill[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        skill[i]=vec[i-low];
    }
    return cnt;
}



int merge_sort(vector<int>& skill,int low ,int high){
    int cnt=0;
    if(low==high) return cnt;
    int mid=(low+high)/2;
    cnt+=merge_sort(skill, low,  mid);
    cnt+=merge_sort(skill,mid+1,high);
    cnt+=sorting(skill,low,mid,high);
    return cnt;
}




int team(vector <int> & skill, int n){
   return merge_sort(skill,0,n-1);
}


int main(){

    return 0;
}