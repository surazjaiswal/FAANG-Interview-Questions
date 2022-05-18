#include <bits/stdc++.h>
using namespace std;

void getProductArr(vector<long long> &nums)
{
    long long n = nums.size();
    vector<long long> ans(n), left(n), right(n);

    left[0] = 1;
    right[n - 1] = 1;

    for (long long i = 1; i < n; i++)
        left[i] = left[i - 1] * nums[i - 1];

    for (long long i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * nums[i + 1];

    for (long long i = 0; i < n; i++)
        ans[i] = left[i] * right[i];

    for (long long i : ans)
        cout << i << " ";

    // return ans;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    // long long n;
    // cin >> n;

    // vector<long long> nums(n);
    // for (long long i = 0; i < n; i++)
    //     cin >> nums[i];

    vector<long long> nums = {1, 2, 3, 4};
    getProductArr(nums);

    return 0;
}