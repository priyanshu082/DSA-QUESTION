#include <iostream>
#include <cmath>

using namespace std;


void f1(int n, string name)
{
    for (int i = 1; i <= n; i++)
        if (i <= n)
        {
            cout << name << endl;
        }
}


void f2(int i)
{
    if (i < 1)
    {
        return;
    }
    cout << i << endl;
    f2(i - 1);
}


void sumf(int i, int sum = 0)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumf(i - 1, sum + i);
}


void factorial(int n,int product=1)
{
    if (n  < 1)
    {
        cout << product;
        return;
    }
    else
    {
        
        factorial(n - 1,product*n);
    }
}


bool palindrom(int i,string &s){
   if (i>=s.size()/2) return true;
   if(s[i]!=s[s.size()-1-i]) return false;
   return palindrom(i+1,s);
}


int fibo(int n){
        if(n<=1) return n;
        int last=fibo(n-1);
        int slast=fibo(n-2);
        
        return last+slast;
    
}

int main()
{
    string s= "12321";
   cout<<fibo(4);

    

    return 0;
}