#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;

        for (int i = 0; i < arr1.size(); i++)
        {
            // case 1:
            max1 = max(arr1[i] + arr2[i] + i, max1);
            min1 = min(arr1[i] + arr2[i] + i, min1);
            // case 2:
            max2 = max(arr1[i] + arr2[i] - i, max2);
            min2 = min(arr1[i] + arr2[i] - i, min2);
            // case 3:
            max3 = max(arr1[i] - arr2[i] + i, max3);
            min3 = min(arr1[i] - arr2[i] + i, min3);
            // case 4:
            max4 = max(arr1[i] - arr2[i] - i, max4);
            min4 = min(arr1[i] - arr2[i] - i, min4);
        }

        int diff1 = max1 - min1;
        int diff2 = max2 - min2;
        int diff3 = max3 - min3;
        int diff4 = max4 - min4;

        return max({diff1, diff2, diff3, diff4});
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> arr1(n), arr2(n);

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    Solution sln;
    int ans = sln.maxAbsValExpr(arr1, arr2);
    cout << ans << endl;

    return 0;
}