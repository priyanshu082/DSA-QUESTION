#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        if (k == 1)
        {

            if (is_sorted(nums.begin(), nums.end()))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {

            cout << "YES" << endl;
        }
    }
}