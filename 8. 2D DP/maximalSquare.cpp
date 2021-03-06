// https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {

        // 1 1 1
        // 1 1 1
        // 1 1 1

        // for a sqaure len(row) == len(diagonal) == len(col), which is number of 1's is same
        // for current cell sq that can be formed will be with the help of left, diagonal, above cell

        int row = matrix.size();
        int col = matrix[0].size();

        if (row == 0)
            return 0;

        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int maxSqr = 0;

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    int a = dp[i - 1][j - 1]; // diagonal
                    int b = dp[i - 1][j];     // above
                    int c = dp[i][j - 1];     // left
                    dp[i][j] = 1 + min({a, b, c});
                    maxSqr = max(maxSqr, dp[i][j]);
                }
            }
        }
        return maxSqr * maxSqr;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> nums[i][j];

    Solution s;
    cout << s.maximalSquare(nums) << endl;

    return 0;
}