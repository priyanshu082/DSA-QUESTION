#include<iostream>

using namespace std;

int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        long long sign=1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) sign=-1;


        long long newDividend=llabs(dividend);
        long long newDivisor=llabs(divisor);

        long long q=0;

        while(newDividend>=newDivisor){
            long long temp=newDivisor;
            long long multi=1;
            while(newDividend>=(temp<<1)){
                temp<<=1;
                multi<<=1;
            }

            newDividend-=temp;
            q+=multi;
        }
        return static_cast<int>(sign*q);
    }

int main(){

    return 0;
}