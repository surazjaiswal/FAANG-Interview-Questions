#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void getAvg(vector<int> &nums, int sz)
    {
        int n = nums.size();
        if (n < sz)
            return;

        vector<double> avgs;
        int sum = 0;
        int i = 0, j = 0;
        while (j < sz)
        {
            sum += nums[j++];
            avgs.push_back((sum * 1.0) / j);
        }

        while (j < n)
        {
            sum -= nums[i++];
            sum += nums[j++];
            avgs.push_back((sum * 1.0) / sz);
        }

        for (auto i : avgs)
        {
            cout << fixed << setprecision(4) << i << " ";
        }
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

    vector<int> nums;
    int x;
    while (cin >> x)
    {
        if (x == -1)
            break;

        nums.push_back(x);
    }

    Solution s;
    s.getAvg(nums, n);

    return 0;
}