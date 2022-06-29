#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0],nums[1]);
        
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
        
    }
};

int rob(vector<int> &nums, int n, vector<int> &dp)
{

    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = max(nums[n] + rob(nums, n - 2, dp), rob(nums, n - 1, dp));
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        vector<int> dp(n, -1);
        cout << rob(nums, n - 1, dp) << endl;
    }

    return 0;
}