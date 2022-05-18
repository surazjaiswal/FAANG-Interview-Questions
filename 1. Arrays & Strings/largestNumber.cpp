#include <bits/stdc++.h>
using namespace std;

void getLargest(int n)
{
    vector<int> nums;
    int num = n;
    while (num)
    {
        int r = num/10;
        nums.push_back(r);
        num /= 10;
    }

    reverse(nums.begin(), nums.end());

    int sz = nums.size();
    int i = sz - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }

    if (i <= 0)
    {
        cout << -1 << endl;
        return;
    }

    int j = sz - 1;
    while (j >= 0 && nums[j] <= nums[i - 1])
    {
        j--;
    }

    swap(nums[i - 1], nums[j]);
    reverse(nums.begin() + i, nums.end());

    num = 0;
    for (int i : nums)
    {
        num = num*10 + i;
        cout<<num<<" ";
    }
    cout << num << endl;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    getLargest(n);

    return 0;
}
