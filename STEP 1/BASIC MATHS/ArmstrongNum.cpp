#include <iostream>
#include <cmath>

using namespace std;

int  main(){
    int n,p,lastDigit,sum=0;
    cin>> n;
    p=n;

    while(n>0)
    {
      lastDigit=n%10;
      sum=sum+(lastDigit*lastDigit*lastDigit);
      n=n/10;
    }

    if (sum==p) cout<< "The number is Armstrong number";
    else cout<< "The number is not Armstrong number";
    return 0;
}