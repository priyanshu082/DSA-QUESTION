#include<iostream>

using namespace std;

void solve(int* p){
  *p=*p+5;
  
}

int main(){

  int a=5;
  
  solve(&a);
  cout<<a<<endl;

  return 0;
    
}