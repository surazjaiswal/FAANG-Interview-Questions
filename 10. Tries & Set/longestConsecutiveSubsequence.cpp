// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        int max_len = 0;
        for (int i : nums)
        {
            if (mp[i - 1] == 0)
            {
                // current number can start the chain
                int cnt = 0, num = i;
                while (mp[num])
                {
                    cnt++;
                    num++;
                }
                max_len = max(max_len, cnt);
            }
        }
        return max_len;
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}