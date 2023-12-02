#include<iostream>

using namespace std;


template<class t1,class t2>
t1 avg(t1 a,t2 b){
    return (a+b)/2;
}

int main(){
    float x=5;
    cout<<avg(x,2.5);

    return 0;
}