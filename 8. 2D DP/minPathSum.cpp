#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int k = 1; k < n; k++)
            grid[0][k] += grid[0][k - 1];

        for (int k = 1; k < m; k++)
            grid[k][0] += grid[k - 1][0];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
        }

        // for(auto it : grid){
        //     for(auto i:it)
        //         cout<<i<<" ";
        //     cout<<endl;
        // }

        return grid[m - 1][n - 1];
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
    cout << s.minPathSum(nums) << endl;
    return 0;
}