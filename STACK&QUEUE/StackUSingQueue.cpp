#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class MyStack {
public:
     queue<int> queue1;
     queue<int> queue2;
    MyStack() {
       
    }
    
    void push(int x) {
        queue1.push(x);
    }
    
    int pop() {
        while(queue1.size()>1){
            queue2.push(queue1.front());
            queue1.pop();
        }
       int popped_ele=queue1.front();
        queue1.pop();
        swap(queue1,queue2);
        return popped_ele;
    }
    
    int top() {
       return queue1.back();
    }
    
    bool empty() {
        return queue1.empty();
    }
};

int main(){

    return 0;
}