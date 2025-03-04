#include <iostream>
#include <vector>

using namespace std;

class Solution{
    vector<string> ans;
public:

    void find (int num,string s,int c){
        if(num==0){
            ans.push_back(s);
            return;
        } 
        find(num-1,s+"0",0);
        if(c == 0){
            find(num-1,s+"1",1);
        }
        
        
    }
    
    vector<string> generateBinaryStrings(int num){
        string s="0";
        string s1="1";
        find(num-1,s,0);
        find(num-1,s1,1);
        return ans;
    }
};

int main(){
    int t = 1;
    cin >> t;

    while(t--){
        //Input
        int n; 
        cin >> n;

        Solution obj;
        vector<string> v = obj.generateBinaryStrings(n);
        
        for(auto it:v) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}