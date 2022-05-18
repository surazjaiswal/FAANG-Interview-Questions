#include <bits/stdc++.h>
using namespace std;

void getRanges(vector<int> &nums)
{

    int n = nums.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        while ((i + 1 < n) && (nums[i] + 1 == nums[i + 1]))
        {
            i++;
        }
        int b = nums[i];
        ans.push_back({a, b});
    }

    for (auto it : ans)
    {
        if (it.first != it.second)
            cout << it.first << "->" << it.second << " ";
        else
            cout << it.first << " ";
    }
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    // int n;
    // cin >> n;

    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];

    vector<int> nums = {0, 1, 2, 5, 7, 8, 10};
    getRanges(nums);

    return 0;
}