#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int n = s.length();
    bool dp[n][n];
    int cnt = 0;
    // gap strategy
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; i < n && j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = false;
            }

            if (dp[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{

    string str;
    cin >> str;
    cout << solve(str) << endl;
    return 0;
}