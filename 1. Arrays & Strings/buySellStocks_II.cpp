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
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            profit += nums[i] - nums[i - 1];
        }
    }
    cout << profit << endl;

    return 0;
}