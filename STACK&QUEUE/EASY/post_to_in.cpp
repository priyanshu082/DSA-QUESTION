// User function Template for C++
#include<iostream>
using namespace std;

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        stack<string> st;
        int i =0;
        while(i<s.size()){
            if(isalnum(s[i])){
                string temp(1, s[i]);
                st.push(temp);
            }else{
                string t1=st.top();st.pop();
                string t2=st.top();st.pop();
                string temp="("+t2+s[i]+t1+")";
                st.push(temp);
            }
            i++;
        }
        
        return st.top();
    }
};

int main(){
    return 0;
}