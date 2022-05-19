// https://leetcode.com/problems/first-missing-positive/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            if (i > 0)
                mp[i]++;
        }

        int i = 1;
        while (mp[i])
        {
            i++;
        }

        return i;
    }
};

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

    Solution s;
    cout << s.firstMissingPositive(nums) << endl;

    return 0;
}