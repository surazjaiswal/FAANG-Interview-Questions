// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode *buildTree(vector<int> inorder, vector<int> preorder)
    {
        int n = preorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        int preIdx = 0;

        TreeNode *root = solve(inorder, preorder, preIdx, 0, n - 1, n);
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &preorder, int preIdx, int in_start, int in_end, int n)
    {
        if (preIdx >= n || in_start > in_end)
            return NULL;

        int num = preorder[preIdx];
        int pos = mp[num];

        preIdx++;

        TreeNode *node = solve(inorder, preorder, preIdx, in_start, pos - 1, n);
        TreeNode *node = solve(inorder, preorder, preIdx, pos + 1, in_end, n);

        return node;
    }
};

TreeNode *createBTree()
{
    TreeNode *root;
    cout << "Enter val : ";
    int x;
    cin >> x;

    if (x != -1)
        root = new TreeNode(x);
    else
        return NULL;

    cout << "\nEnter value for Left Node of " << x << endl;
    root->left = createBTree();
    cout << "\nEnter value for Right Node of " << x << endl;
    root->right = createBTree();

    return root;
}

void inOrder(TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

class SolutionII
{
public:
    void getRightView(TreeNode *root)
    {
        vector<int> ans;
        traverse(root, ans, 1);

        for (int i : ans)
            cout << i << " ";
    }

    void traverse(TreeNode *root, vector<int> &ans, int level)
    {
        if (!root)
            return;

        if (ans.size() < level)
            ans.push_back(root->val);

        traverse(root->right, ans, level + 1);
        traverse(root->left, ans, level + 1);
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    TreeNode *root;
    root = createBTree();
    inOrder(root);

    return 0;
}