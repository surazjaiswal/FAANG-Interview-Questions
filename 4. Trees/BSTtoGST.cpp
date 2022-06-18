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
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        revInorder(root, sum);
        return root;
    }

    void revInorder(TreeNode *root, int &sum)
    {
        if (!root)
            return;

        revInorder(root->right, sum);
        sum += root->val;
        root->val = sum;
        revInorder(root->left, sum);
    }
};

int main()
{
    return 0;
}