#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int ans = INT_MIN;
    int curr_product = 1;

    //  main assertion is that the max product will start from starting index  or it willl end at the last index or both

    for (int i = 0; i < n; i++)
    {
        curr_product *= nums[i];
        ans = max(ans, curr_product);

        if (curr_product == 0)
        {
            curr_product = 1;
        }
    }

    curr_product=1;
    for (int i = n - 1; i >= 0; i--)
    {
        curr_product *= nums[i];
        ans = max(ans, curr_product);

        if (curr_product == 0)
        {
            curr_product = 1;
        }
    }

    cout << ans << endl;

    return 0;
}