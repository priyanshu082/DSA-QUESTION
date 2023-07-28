#include<iostream>
using namespace std;

//brutte force will be running two loops and checking for each one;
int team(vector <int> & skill, int n)
{
   int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           if(skill[i]>2*skill[j]) cnt++;
       }
   }
   return cnt;
}



//optimal solution for this 
void sorting(vector<int>& skill,int low,int mid,int high){
    int left=low;
    int right=mid+1;

    vector<int> vec;
   
   
    while(left<=mid && right<=high){
       
        if(skill[left]<=skill[right]){
            vec.push_back(skill[left]);
            left++;
        } 
        else{
            vec.push_back(skill[right]);
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
 
}

int count_pairs(vector<int> &skill,int low,int mid,int high){
    int right=mid+1;
   int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && (long long)skill[i]>2LL*(long long)skill[right]) right++;
        cnt+=(right-mid-1);
    }
    return cnt;
}

int merge_sort(vector<int>& skill,int low ,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=merge_sort(skill, low,  mid);
   cnt+=merge_sort(skill,mid+1,high);
    cnt+=count_pairs(skill,low,mid,high);
   sorting(skill,low,mid,high);
   return cnt;
}

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
         return merge_sort(nums,0,n-1); 
    }

int main(){

    return 0;
}