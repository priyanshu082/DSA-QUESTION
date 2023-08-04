#include<iostream>

using namespace std;

//brute force soltuion is
class Solution {
public:
    double myPow(double x, int n) {
       
       if(n==0) return 1;
        if(n>=0){
             double p=x;
        for(long long i=2;i<=n;i++){
            x=x*p;
        }
        } else {
            double m=1/x;
            if(n==-1) return m;
            double ans=1/x;
            n=-n;
             for(int i=2;i<=n;i++){
            ans=ans*m;
        x=ans;
        }
        }
        return x;
    }
};

//optimal appraoch is 
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;

        if (x == 1)
            return 1;

        long long abs_n = n < 0 ? -(long long)n : n;
        double result = 1;

        while (abs_n > 0) {
            if (abs_n % 2 == 1)
                result *= x;
            x *= x;
            abs_n /= 2;
        }

        return n < 0 ? 1 / result : result;
    }
};


int main(){

    return 0;
}