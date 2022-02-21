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

    int left = 0, right = n - 1;
    int i = 0;
    while (i <= right)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[left]);
            i++;
            left++;
        }
        else if (nums[i] == 2)
        {
            swap(nums[i], nums[right]);
            right--;
        }
        else
        {
            i++;
        }
    }

    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}