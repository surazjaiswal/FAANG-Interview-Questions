#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // here number in the array lies between [1,n]
    // so the idea is to mark the index corresponding to the number as negative;
    // and later on chceking (simultaneously) if current number index has already appeared (marked as negative)
    // if marked as negative then push it to ans vector

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else
        {
            nums[index] *= -1;
        }
    }
    cout << "[";
    int i = 0;
    for (; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans[i] << "]" << endl;

    return 0;
}