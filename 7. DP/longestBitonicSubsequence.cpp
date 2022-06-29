#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    // in this we need to use bidirectional dp
    // to find number of lesser number of numbers towards its left & right including itself
    // this can be using help of two lists, leftPart, rightPart
    // and then find length of longest bitonic subsequence for every element (leftPart[i] + rightPart[i] - 1) then return max of them

    int n = nums.size();
    vector<int> leftNums(n, 1), rightNums(n, 1); // 1 because number is begin considered as part of each of its bitonic subsequence

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
                leftNums[i] = max(leftNums[i], leftNums[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i])
                rightNums[i] = max(rightNums[i], rightNums[j] + 1);
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; i++)
        max_len = max(max_len, leftNums[i] + rightNums[i] - 1);

    return max_len;
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

        cout << solve(nums) << endl;
    }

    return 0;
}