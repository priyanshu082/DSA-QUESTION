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
        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }

        int ans=INT_MIN;
        ans=max(ans,nums[0]);
        int i=1;
        for(i=1;i<n;i++){
            if(nums[i]<k){
                int fuel=nums[i]-nums[i-1];
                ans=max(ans,fuel);
            }else break;
        }
        ans=max(ans,2*(k-nums[i-1]));
        cout<<ans<<endl;

    }
    return 0;
}