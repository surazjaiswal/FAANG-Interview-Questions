// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

vector<vector<int>> traverse(TreeNode *root)
{
    if (!root)
        return {};

    vector<vector<int>> ans;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> vt;
        while (sz--)
        {
            TreeNode *node = q.front();
            q.pop();

            vt.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (level & 1)
            reverse(vt.begin(), vt.end());
        ans.push_back(vt);

        level++;
    }
    return ans;
}

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