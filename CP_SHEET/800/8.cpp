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
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>> nums[i];

        bool found=false;

        for (int i = 0; i <n; i++) {
           if(nums[i]==m){
            found=true;
            break;
           }
        }

        if(found) cout << "YES" << endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
