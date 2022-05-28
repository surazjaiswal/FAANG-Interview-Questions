// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    unordered_map<int, int> mp;
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};

        traverse(root, 0);

        vector<int> ans(mp.size());
        for (auto it : mp)
        {
            ans[it.first] = it.second;
        }

        return ans;
    }

    void traverse(TreeNode *root, int level)
    {
        if (!root)
            return;

        if (mp[level])
        {
            mp[level] = max(mp[level], root->val);
        }
        else
        {
            mp[level] = root->val;
        }

        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
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