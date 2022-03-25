#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // base edge cases
    // for single element, always a peak
    if (n == 1)
    {
        cout << "true" << endl;
        return 0;
    }

    // for strictly increasing and decreasing plots
    if (nums[0] > nums[1])
    {
        cout << "true" << endl;
        return 0;
    }

    if (nums[n - 1] > nums[n - 2])
    {
        cout << "true" << endl;
        return 0;
    }

    int start = 1, end = n - 2;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        // 3 cases aries
        // if mid is the peak element
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            cout << "true" << endl;
            return 0;
        }
        else if (nums[mid] < nums[mid + 1])
        {
            // here peak lies ahead of mid
            start = mid + 1;
        }
        else if (nums[mid] < nums[mid - 1])
        {
            // here peak lies behind the mid
            end = mid - 1;
        }
    }

    cout << "false" << endl;

    return 0;
}