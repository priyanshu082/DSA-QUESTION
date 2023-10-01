#include<iostream>

using namespace std;

void change(int *ptr){
    *ptr=*ptr+10;
}

int main(){

    int a =5;
    int *ptr =&a;
    cout<<a<<endl;
    cout<<*ptr<<endl;
    change(ptr);
    cout<<a<<endl;
    
}