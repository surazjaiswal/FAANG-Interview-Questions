// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time  :  O(N)
    int climbStairs(int n)
    {

        // this appraoch takes constant space

        // if (n <= 2)
        //     return n;

        // int a, b, c; // a->n-2, b->n-1, c->n
        // a = 1, b = 2;
        // for (int i = 3; i <= n; i++)
        // {
        //     c = a + b;
        //     a = b;
        //     b = c;
        // }
        // return c;

        // this approach takes O(N) space
        int dp[50];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    int n;
    cin >> n;

    return 0;
}