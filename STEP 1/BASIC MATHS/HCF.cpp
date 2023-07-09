#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a,b,GCD;
    cin>>a>>b;
     for(int i=min(a,b);i>0;i--){
        if(a%i==0&&b%i==0){
            GCD=i;
            break;
        }
     }

     cout<< "The GCD of of two numbers are "<< GCD<<endl;
    return 0;

}