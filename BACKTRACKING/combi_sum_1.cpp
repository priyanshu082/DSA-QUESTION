#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void r(vector<vector<int>>& ans, vector<int>& c, int target, int i, vector<int> temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if(target<0 ) return ;

        for (int j = i; j < c.size(); j++) {
            temp.push_back(c[j]);
            if(c[j]>target) break;
            r(ans, c, target - c[j], j , temp); // Move to the next index (no reuse)
            temp.pop_back(); // Backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        // vector<vector<int>> dp(candidates.size()+1,{});
        sort(candidates.begin(), candidates.end()); 
        r(ans, candidates, target, 0, temp);
        return ans;
    }
};

int main(){
    return 0;
}