#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int top;
    int size;
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(top == size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        top--;
    }
    void peek(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<"Top element is: "<<arr[top]<<endl;
    }
    void isEmpty(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<"Stack is not Empty"<<endl;
    }
    void display(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    return 0;
}