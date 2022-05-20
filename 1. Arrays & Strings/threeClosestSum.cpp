#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int csum;
        for (int i = 0; i <= nums.size() - 3; i++)
        {
            int sum = 0;
            int j = i + 1, k = nums.size() - 1;
            sum += nums[i] + nums[j] + nums[k];
            while (j < k)
            {
                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    csum = sum;
                }
                if (sum < target)
                {
                    sum -= nums[j];
                    sum += nums[++j];
                }
                else if (sum > target)
                {
                    sum -= nums[k];
                    sum += nums[--k];
                }
                else
                {
                    return sum;
                }
            }
        }
        return csum;
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
    int target;
    cin >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution s;
    cout << s.threeSumClosest(nums, target) << endl;

    return 0;
}