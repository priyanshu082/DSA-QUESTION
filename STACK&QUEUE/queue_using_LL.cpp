#include<iostream>

using namespace std;

class Node{
    
   
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }

};

class Queue{
    Node* rear;
    Node* front;
    public:
    Queue(){
        rear=NULL;
        front=NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    

    void dequeue(){
        if(front==NULL){
            cout<<"Queue is Emptys"<<endl;
            return;
        }
        Node* temp=front;
        if(front==rear){
            front=NULL;
            rear=NULL;
        }else{
            front=front->next;
        }
        delete temp;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        if(front==NULL) return true;
        else return false;
    }


};

int main(){
    return 0;
}