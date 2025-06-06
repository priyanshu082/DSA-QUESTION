#include<iostream>

using namespace std;



class Solution {
  public:
  int priority(char op) {
        if(op == '^') return 3;
        if(op == '*' || op == '/') return 2;
        if(op == '+' || op == '-') return 1;
        return 0;
    }

    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        int i=0;
        string ans="";
        while(i<s.size()){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while( !st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && priority(st.top()) >= priority(s[i])){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};

int main(){
    return 0;
}