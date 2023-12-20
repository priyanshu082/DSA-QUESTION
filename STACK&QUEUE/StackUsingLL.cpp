#include <iostream>

using namespace std;

template <typename T>

class node
{
public:
    int data;
    node *next;

    node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class MyStack
{
private:
    node<T> *top;

public:
    MyStack() : top(nullptr){}

    void push(T val)
    {
        node<T> *newNode = new node<T>(val);
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            node<T>* popped = top;
            T poppedVal = top->data;
            top = top->next;
            delete popped;
            return poppedVal;
        }
    }

    T peek()
    {
        if (empty())
        {
            cout << "Stack is Empty" << endl;
        }

        else
        {
            return top->data;
        }
    }

    bool empty()
    {
        return top==nullptr;
    }
};

int main()
{

    MyStack<int> S;
    S.push(5);
    S.push(10);
    S.push(3);
    S.push(2);

    cout << "The top element is " << S.peek() << endl;
    cout << "Element which is popped out " << S.pop() << endl;
    cout << "The top element is " << S.peek() << endl;
    cout << "Element which is popped out " << S.pop() << endl;
    cout << "The top element is " << S.peek() << endl;
    S.push(5);
        cout << "The top element is " << S.peek() << endl;

    


        return 0;
}