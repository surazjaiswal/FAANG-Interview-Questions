#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
        {
            cin >> nums[i];
        }

        unordered_map<int, int> mp;
        mp[0]=1;
        int pre_sum = 0, ans = 0;
        for (int num : nums)
        {
            pre_sum += num;
            if (mp.count(num))
            {
                ans += mp[num];
            }
            mp[pre_sum]++;
        }

        cout << ans << endl;
    }

    return 0;
}