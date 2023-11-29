#include<iostream>

using namespace std;

class CircularQueue {
    private:
    int f,r,size;
    int  *arr;

    public:
    CircularQueue(int x) {
        f=-1;
        r=-1;
        size=x;
        arr= new int[size];
    }

    bool isFull(){
        if((r+1)%size==f) return true;
        return false;
    }

    bool isEmpty(){
        if(f==-1) return true;
        return false;
    }

    void insertion(int val){
        if(isFull()) cout<<"Queue is full"<<endl;
        else if(isEmpty()){
            f=0;
            r=0;
            arr[r]=val;
            cout<<"Inserted"<<endl;
        } else{
            r=(r+1)%size;
            arr[r]=val;
            cout<<"Inserted"<<endl;
        }
    }

    void deletion(){
        if(isEmpty()) cout<<"Queue is Empty!!"<<endl;

        int data = arr[f];
        arr[f] = -1;
        cout<<"Deleted"<<endl;

        if(f==r) f=-1,r=-1;
        else if(f==size-1) f=0;
        else f++;
    }

    void display(){
        int i;
        if(isEmpty()) cout<<"Queue is Empty"<<endl;

        cout<<"Elements in circular queue are: "<<endl;
        cout<< "Front="<<f<<endl;
        
        if(r>=f){
            for(i=f;i<=r;i++) cout<<arr[i]<<" ";
        } else if(r<f){
            for(i=f;i<=size-1;i++) cout<<arr[i]<<" ";
            for(i=0;i<=r;i++) cout<<arr[i]<<" ";
        }
            cout<<endl;
            cout<<"Rear="<<r<<endl;
    }
};

int main(){
    CircularQueue q(5);
    int value;
    int x;
    cout<<"1.Insertion\n2.Deletion\n3.Display\n4.Exit"<<endl;

    while(1){
        cout<<"Enter the operation:";
        cin>> x;
        switch(x){
            case 1:
            cout<<"Enter the element to push : ";
            cin>>value;
            q.insertion(value);
            break;

            case 2:
            q.deletion();
            break;

            case 3:
            q.display();
            break;

            case 4:
            cout<<"Exited"<<endl;
            exit(0);
        }
    }
    return 0;
}