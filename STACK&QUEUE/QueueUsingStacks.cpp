#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int popped=s1.top();
        s1.pop();
        while(s2.size()>0){
            s1.push(s2.top());
            s2.pop();
        }
        return popped;
    }
    
    int peek() {
        while(s1.size()>1){
            s2.push(s1.top());
            s1.pop();
        }
        int peek=s1.top();
        s2.push(s1.top());
        s1.pop();
        while(s2.size()>0){
            s1.push(s2.top());
            s2.pop();
        }
        return peek;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){

    return 0;
}