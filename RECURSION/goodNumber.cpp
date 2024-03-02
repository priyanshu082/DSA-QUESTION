#include<iostream>

using namespace std;

int main(){
    return 0;
}

class Solution {
public:

    long long pow(long long n,long long x){
        const long long  mod= 1000000007;
        if(x==0) return 1;
        if(x==1) return n%mod;

        long long ans = 1;
        long long know = pow(n, x / 2) % mod;
        if (x % 2) ans = (ans * n) % mod;
        ans = (ans * ((know * know) % mod)) % mod;
        return ans;

    }

    int countGoodNumbers(long long n) {
        long long  mod= 1000000007;
        long long ans=1;
        ans=pow(20,n/2);
        if(n%2==1) ans=(ans*5)%mod;
        ans=static_cast<int>(ans);
        return ans;
    }
};