#include<iostream>
#include<stack>


using namespace std;

class Queue{
    private:
    stack<int> in;
    stack<int> out;


    public:
    void enqueue(int data){
        in.push(data);
    }

    void pop(){
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        if (out.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Dequeued: " << out.top() << endl;
        out.pop();
    }

    int top(){
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        if (out.empty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return out.top();  
    }

    bool isEmpty() {
        return in.empty() && out.empty();
    }


};

int main(){
    return 0;
}