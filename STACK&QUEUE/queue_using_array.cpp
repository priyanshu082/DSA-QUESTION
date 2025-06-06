#include<iostream>

using namespace std;

class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int size){
        this->size= size;
        arr = new int[size];
        front=-1;
        rear=-1;
    }
    void enqueue(int data){
        if(rear==size-1){
            cout<<"Queue is Full"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]= data;
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
            return ;

        }
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
    }
    void peek(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Front element is: "<<arr[front]<<endl;
    }
    void isEmpty(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Queue is not Empty"<<endl;
    }
    void display(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    return 0;

}