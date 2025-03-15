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
        for (int j = i; j < c.size(); j++) {
            if (j > i && c[j] == c[j - 1]) continue; // Skip duplicate elements
            if (c[j] > target) break; // Stop if current number is greater than target
            temp.push_back(c[j]);
            r(ans, c, target - c[j], j + 1, temp); // Move to the next index (no reuse)
            temp.pop_back(); // Backtrack
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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