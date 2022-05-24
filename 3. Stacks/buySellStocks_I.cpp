#include <bits/stdc++.h>
using namespace std;

int getProfit(vector<int> &nums)
{
    int minNum = nums[0];
    int maxProfit = 0;
    for (int i : nums)
    {
        int profit = i - minNum;
        maxProfit = max(maxProfit, profit);
        minNum = min(minNum, i);
    }

    return maxProfit;
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

    cout << getProfit(nums) << endl;

    return 0;
}