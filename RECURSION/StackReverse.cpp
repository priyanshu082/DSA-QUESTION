#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:

void insertBottom(std::stack<int>& st,int x){
    if(st.empty() ){
        st.push(x);
        return ;
    }
    int temp=st.top();
    st.pop();
    insertBottom(st,x);
    
    st.push(temp);
    
}
    void Reverse(stack<int> &st){
        if(!st.empty()){
            int x=st.top();
            st.pop();
            Reverse(st);
            insertBottom(st,x);
        }
    }
};

int main(){

    return 0;
}