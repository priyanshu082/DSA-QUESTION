#include<iostream>

using namespace std;

template<class t1=char,class t2=float>
class pp{
    protected:
    t1 a;
    t2 b;

    public:
    pp(t1 x,t2 y):a(x),b(y){}

    void display(){
        cout<<a<<endl;
        cout<<b<<endl;
    }
};

int main(){

    pp<> q(a,2);

     q.display();


    return 0;
}