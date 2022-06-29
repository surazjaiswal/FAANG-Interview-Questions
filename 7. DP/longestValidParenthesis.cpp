#include <bits/stdc++.h>
using namespace std;

/** 
 * LeetCode Solutions
 * Approach 4: Without extra space
 * Algorithm
 *
 * In this approach, we make use of two counters leftleft and rightright.
 * First, we start traversing the string from the left towards the right and for every \text{‘(’}‘(’ encountered, we increment the leftleft counter and for every \text{‘)’}‘)’ encountered, we increment the rightright counter.
 * Whenever leftleft becomes equal to rightright, we calculate the length of the current valid string and keep track of maximum length substring found so far.
 * If rightright becomes greater than leftleft we reset leftleft and rightright to 00.
 * Next, we start traversing the string from right to left and similar procedure is applied.
 *
 * 
 * Complexity Analysis
 * 
 * Time complexity: O(n)O(n). Two traversals of the string.
 * 
 * Space complexity: O(1)O(1). Only two extra variables leftleft and rightright are needed.
 * 
 */

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int open = 0, close = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
                ans = max(ans, close * 2);

            else if (close >= open)
                open = 0, close = 0;
        }

        open = 0, close = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
                ans = max(ans, open * 2);

            else if (open >= close)
                open = 0, close = 0;
        }

        return ans;
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

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}