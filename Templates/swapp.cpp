#include<iostream>

using namespace std;

template<class t>
void swapp(t &a,t& b){
    t temp=a;
    a=b;
    b=temp;
}

int main(){

int x=5;int y=10;
    swapp(x,y);

    cout<<x;

return 0;
}