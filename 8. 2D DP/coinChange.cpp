// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        int dp[n + 1][amt + 1];

        // number of coins is zero, so no sum can be build up
        for (int j = 0; j < amt + 1; j++)
            dp[0][j] = INT_MAX - 1; // to avoid any overflow

        // amount is zero, coins needed is zero
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        // variation of unbounded knapsack problem
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amt + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][amt] > amt)
            return -1;
        else
            return dp[n][amt];
    }
};

int main()
{
    int target, n;
    cin >> target >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    Solution s;
    cout << s.coinChange(coins, target) << endl;

    return 0;
}