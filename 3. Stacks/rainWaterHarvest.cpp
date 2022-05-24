#include <bits/stdc++.h>
using namespace std;

int getMaxWater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n), right(n);

    int maxLeft = nums[0];
    for (int i = 0; i < n; i++)
    {
        maxLeft = max(maxLeft, nums[i]);
        left[i] = maxLeft;
    }

    int maxRight = nums[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        maxRight = max(maxRight, nums[i]);
        right[i] = maxRight;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - nums[i];
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

    cout << getMaxWater(nums) << endl;

    return 0;
}
