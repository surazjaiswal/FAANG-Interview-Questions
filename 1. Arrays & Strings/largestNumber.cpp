#include <bits/stdc++.h>
using namespace std;

void getLargest(long long n)
{
    vector<long long> nums;
    long long num = n;
    while (num)
    {
        long long r = num % 10;
        nums.push_back(r);
        num /= 10;
    }

	if(nums.size() > 9){
		cout<<-1<<endl;
		return;
	}

    reverse(nums.begin(), nums.end());

    long long sz = nums.size();
    long long i = sz - 1;
    while (i > 0 && nums[i - 1] >= nums[i])
    {
        i--;
    }

    if (i <= 0)
    {
        cout << -1 << endl;
        return;
    }

    long long j = sz - 1;
    while (j >= 0 && nums[j] <= nums[i - 1])
    {
        j--;
    }

    swap(nums[i - 1], nums[j]);
    reverse(nums.begin() + i, nums.end());

    num = 0;
    for (long long i : nums)
    {
        num = num * 10 + i;
    }
    cout << num << endl;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    long long n;
    cin >> n;

    getLargest(n);

    return 0;
}
