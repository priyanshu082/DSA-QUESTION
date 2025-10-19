#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int i = 0;
        bool broken = false; // flag to check if we should break

        while(i < n) {
            if(s[i] == '#') {
                i++;
            } else {
                int cnt = 0;
                while(i < n && s[i] == '.') {
                    cnt++;
                    i++;
                }
                if(cnt > 2) {
                    cout << 2 << endl; // break immediately for this test case
                    broken = true;
                    break;
                } else {
                    ans += cnt; // count 1 or 2
                }
            }
        }

        if(!broken) {
            cout << ans << endl;
        }
    }
    return 0;
}
