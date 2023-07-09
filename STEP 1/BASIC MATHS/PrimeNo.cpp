#include <iostream>
#include <cmath>

using namespace std;

int main(){
     int n,cnt=0;
     cin >>n;
     for(int i=1;i<=n;i++){
        if(n%i==0){
         cnt++;
        }
     }

     if(cnt==2) cout<< "Number is prime";
     else cout<< "Number is not prime";

    return 0;
}