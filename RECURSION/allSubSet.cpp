#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<vector<int> > ans;
public:
    void r(int n,vector<int>& nums,vector<int>& vec){
        if(n>nums.size()) return ;
        ans.push_back(vec);
        for(int i=n;i<nums.size();i++){
            vec.push_back(nums[i]);
            r(i+1,nums,vec);
            vec.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
       vector<int> vec;
       r(0,nums,vec);
       return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    vector<vector<int> > ans = obj.subsets(v);
    for(int i=0;i<ans.size();i++){
        cout << "[";
        for(int j=0;j<ans[i].size();j++){
            
             cout << ans[i][j];
             if(j!=ans[i].size()-1) cout << ",";
        }
        cout << "]";
        if(i!=ans.size()-1) cout << ",";
    }
    cout<<endl;
    cout<<ans.size();
    return 0;

}