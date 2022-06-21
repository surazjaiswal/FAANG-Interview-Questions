// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
using namespace std;

void containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(nums[i]))
        {
            int diff = abs(mp[nums[i]] - i);
            if (diff <= k)
            {
                cout << "true" << endl;
                return;
            }
        }
        mp[nums[i]] = i;
    }

    cout << "false" << endl;
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