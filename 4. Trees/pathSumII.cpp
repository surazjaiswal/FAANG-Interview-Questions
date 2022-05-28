// https://leetcode.com/problems/path-sum-ii/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->val = val;
    }
};

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSumII(TreeNode *root, int target)
    {
        if (!root)
            return {};
        vector<int> vt;
        int sum = 0;
        traverse(root, sum, target, vt);
        return ans;
    }

    void traverse(TreeNode *root, int &sum, int target, vector<int> &vt)
    {
        if (!root)
            return;

        sum += root->val;
        vt.push_back(root->val);
        if (sum == target && (!root->left && !root->right))
        {
            ans.push_back(vt);
        }

        traverse(root->left, sum, target, vt);
        traverse(root->right, sum, target, vt);
        vt.pop_back();
        sum -= root->val;
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