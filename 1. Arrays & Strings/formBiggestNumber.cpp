#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2)
{
    return s1 > s2;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            string a = to_string(nums[i]);
            string b = to_string(nums[i + 1]);
            if (a > b)
            {
                swap(nums[i], nums[i + 1]);
            }
        }
        for (int i = nums.size(); i >= 0; i++)
        {
            cout << nums[i];
        }
        cout << endl;
    }

    return 0;
}