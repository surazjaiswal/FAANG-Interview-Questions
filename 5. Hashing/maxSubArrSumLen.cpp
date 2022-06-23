// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

int maxSubArrSumLenK(vector<int> &nums, int k)
{
    // prefix sum concept
    // (y - k) +  (k)
    // -------  -----
    // --------------
    //       (y)

    unordered_map<int, int> mp;
    mp[0] = -1;
    int pSum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int pSum += nums[i];
        if (mp.count(pSum - k))
        {
            ans = max(ans, i - mp[pSum - k]);
        }
        else
        {
            mp[pSum] = i;
        }
    }

    return ans;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}