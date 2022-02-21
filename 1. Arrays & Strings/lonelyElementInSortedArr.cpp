#include <bits/stdc++.h>
using namespace std;

bool checkSingle(int mid, vector<int> &nums)
{
    // if first element
    if (mid == 0 && nums[mid] != nums[mid + 1])
        return true;
    // last element
    if (mid == nums.size() - 1 && nums[mid] != nums[mid - 1])
        return true;
    // left and right element
    if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        return true;
    return false;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            cout << nums[mid] << endl;
            return 0;
        }
        else if (nums[mid - 1] == nums[mid])
        {
            if ((mid - 1) % 2 == 0)
            {
                // this pair starts with even index
                l = mid + 1;
            }
            else
            {
                // this pair starts with odd index, therefore lonely element has been occured before it
                // reduce the high value
                h = mid - 1;
            }
        }
        else if (nums[mid] == nums[mid + 1])
        {
            if (mid % 2 == 0)
            {
                // cureent pair start with even index
                l = mid + 1;
            }
            else
            {
                // this pair starts with odd index, therefore lonely element has been occured before it
                // reduce the high value
                h = mid - 1;
            }
        }
    }

    return 0;
}