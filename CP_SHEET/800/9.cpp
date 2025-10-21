#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans=0;
       
        for(int i=0;i<n-1;i++)
        {
            int val;
            cin>> val;
            ans+=val;

        } 
        

       

         cout << -1*ans << endl;
    }
    return 0;
}
