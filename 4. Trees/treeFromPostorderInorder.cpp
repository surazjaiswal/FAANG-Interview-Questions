// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
    {
        int n = postorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        int postIdx = 0;

        TreeNode *root = solve(inorder, postorder, postIdx, 0, n - 1, n);
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int postIdx, int in_start, int in_end, int n)
    {
        if (postIdx < 0 || in_start > in_end)
            return NULL;

        int num = postorder[postIdx];
        int pos = mp[num];

        postIdx--;

        // in postorder right subtree will be built first then left subtree contry to preorder
        TreeNode *node = solve(inorder, postorder, postIdx, pos + 1, in_end, n);
        TreeNode *node = solve(inorder, postorder, postIdx, in_start, pos - 1, n);

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