// https://leetcode.com/problems/add-one-row-to-tree/

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

TreeNode *addNewNode(TreeNode *root, int val, int depth)
{
    if (!root)
        return root;

    if (depth == 1)
    {
        TreeNode *newNode = new TreeNode(val);
        newNode->left = root;
        return newNode;
    }

    traverse(root, val, depth, 1);
    return root;
}

void traverse(TreeNode *root, int val, int depth, int cnt)
{
    if (!root)
        return;

    if (cnt == depth - 1)
    {
        TreeNode *newNode, *leftNode, *rightNode;
        leftNode = root->left, rightNode = root->right;
        root->left = new TreeNode(val);
        root->right = new TreeNode(val);
        root->left->left = leftNode;
        root->right->right = rightNode;
    }

    traverse(root->left, val, depth, cnt + 1);
    traverse(root->right, val, depth, cnt + 1);
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