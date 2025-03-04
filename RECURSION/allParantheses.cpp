#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {

    vector<string> ans;
public:
    void r(int n,int open,string s){
        if(n<=0 && open<=0){
            ans.push_back(s);
                return ;
        }
        if(open>0){
            r(n,open-1,s+")");
        } 
        if(n>0) r(n-1,open+1,s+"(");
        
          
        
    }
    vector<string> generateParenthesis(int n) {
        string s="(";
        r(n-1,1,s);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    vector<string> v = obj.generateParenthesis(n);
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    
}