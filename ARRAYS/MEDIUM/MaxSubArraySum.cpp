#include <iostream>
#include <vector>

using namespace std;

// brute approach i.e o(n@3)
int maxSubArraySum(int nums[], int n)
{
    int maxi, sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = 0;
            for (int k = j; k <= i; k++)
            {
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

// better approach i.e o(n@2)
int maxSubAarraySum2(int nums[], int n)
{
    int maxi;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
}

// kadanes algo for solving in o(2n) or o(n)
int maxSubArray3(vector<int> &nums)
{

    int n = nums.size();
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int maxi = 0, sum = 0;
    bool allNegative = true;
    int maxElement = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxElement = max(maxElement, nums[i]);
        if (nums[i] >= 0)
        {
            allNegative = false;
        }
    }

    for (auto it : nums)
    {
        sum += it;
        maxi = max(maxi, sum);
        if (sum < 0) sum = 0;
    }

    return allNegative ? maxElement : maxi;
};

int main()
{
      int n;
      cin>>n;
      int arr[n];
      for (int i=0;i<n;i++){
         cin>>arr[i];
      }
    

    int size = sizeof(arr)/sizeof(arr[0]);

    vector<int> nums(arr, arr + size);
    int p = maxSubArray3(nums);

    cout << p << endl;
    return 0;
}