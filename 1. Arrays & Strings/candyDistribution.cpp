#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &rating)
    {
        int n = rating.size();
        vector<int> candy(n);
        candy[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (rating[i] > rating[i - 1])
            {
                candy[i] = candy[i - 1] + 1;
            }
            else
            {
                candy[i] = 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (rating[i] > rating[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i] = candy[i + 1] + 1;
            }
        }
        int sum = 0;
        for (int i : candy)
        {
            sum += i;
        }
        return sum;
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        cin >> ratings[i];

    Solution s;
    cout << s.candy(ratings) << endl;

    return 0;
}