#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        ans = min(ans, abs(nums[i]));
    }

    cout << ans << endl;
    return 0;
}
