#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if (n == 1) {
            cout << 0 << endl; 
            continue;
        }
       
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        for (int i = 0; i + 1 < n; i += 2) {
            ans = max(ans, abs(vec[i] - vec[i + 1]));
        }
        
        cout<< ans<<endl;
    }
}
