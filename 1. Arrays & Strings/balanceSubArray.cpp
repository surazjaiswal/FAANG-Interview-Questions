#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int sum = 0, ans = 0;
    int i = 0;
    
    unordered_map<int, int> mp;
    mp[0] = -1; // base condition mp[sum]=index

    while (i < n)
    {
        if (nums[i] == 0)
        {
            nums[i] = -1;
        }

        sum += nums[i];

        if (mp.count(sum))
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
        i++;
    }
    cout << ans << endl;

    return 0;
}