#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        int n = str.length();
        int max_len = 0, start = 0, end = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    // single char always pallindrome
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    // check pallindromic condition for two alphabet word
                    if (str[i] == str[j])
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    // now chech if first and last char of word are same or not
                    // if same then, they can be pallindrome if char between them are pallindrome
                    if (str[i] == str[j])
                    {
                        if (dp[i + 1][j - 1] == 1)
                        {
                            dp[i][j] = 1;
                        }
                    }
                }
                if (dp[i][j] == 1)
                {
                    if (g + 1 > max_len)
                    {
                        max_len = g + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        // cout << max_len << endl;
        cout << str.substr(start, max_len) << endl;
    }

    return 0;
}
