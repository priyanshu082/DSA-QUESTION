#include <iostream>
#include <cmath>

using namespace std;
 int main(){
    int n ,revNum=0,lastDigit;
    cin>> n;
    while(n>0){
        lastDigit=n%10;
        revNum = revNum*10 + lastDigit;
        n=n/10;

    }

    cout<< revNum;
 }