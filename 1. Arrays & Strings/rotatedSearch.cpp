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
    int k;
    cin >> k;

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == k)
        {
            cout << mid << endl;
            return 0;
        }
        else if (nums[mid] >= nums[low])
        {
            // this means that mid is in the first part
            // now check if target lies in the first part or not
            if (nums[low] <= k && k <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // this means mid lies in the second part
            //  now check tha presence of target in the second part
            if (nums[mid] <= k && k <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}