#include<iostream>

using namespace std;

template<typename t>
class node{
    public :
    int data;
    node* next;

    node(t val):data(val),next(nullptr){}
};

template<typename t>
class MyQueue{
    private:
    node<t> * front;
    node<t> * rear;

    public:
    MyQueue():front(nullptr),rear(nullptr){}

    void push(t val){
        node<t>* newNode=new node<t>(val);
        if(empty()){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
    }

    t pop(){
        if(empty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            node<t>* popped=front;
            front=front->next;
            t popVal=popped->data;
            delete popped;
            if(front==nullptr) rear=nullptr;
            return popVal;
        }
    }

    t peek(){
        if(empty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            return front->data;
        }
    }

    bool empty(){
        return front==nullptr;
    }


};

int main(){


    return 0;
}