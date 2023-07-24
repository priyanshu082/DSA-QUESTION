#include<iostream>


using namespace std;

//brute appraoch for solving the question tc=nlogn+2n    nd sc=n
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                } 
                else {
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};

//tc=n and sorting tc=nlogn optimal appraoch
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
         if(ans.empty()|| intervals[i][0]>ans.back()[1]){
             ans.push_back({intervals[i]});
         }
         else{
             ans.back()[1]=max(ans.back()[1],intervals[i][1]);
         }
        }
        return ans;
    }
};


int main(){
  

    return 0;
}