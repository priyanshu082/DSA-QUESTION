#include<iostream>
#include<queue>

using namespace std;

//using single queue
class Stack{
    queue<int> q;
    public:
    void push(int data){
        q.push(data);
        for(int i =0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        if(q.empty()){
            return -1;
        }
        q.pop();
    }

    int top(){
        if(q.empty()) return -1;
        return q.front();
    }

    int isEmpty(){
        return q.empty();
    }
};

//using two queue
class Stack_2_queue{
    queue<int> q1;
    queue<int> q2;
    public:
    void push(int data){
        q1.push(data);
    }

    void pop(){
        if(q1.empty()) return ;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1,q2);
    }

    int top(){
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

         while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int res = q1.front();
        q2.push(res); // push it back to q2
        q1.pop();
        swap(q1,q2);
        return res;
    }
    
    int isEmpty(){
        return q1.empty();
    }
};

int main(){
    return 0;
}