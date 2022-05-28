// https://leetcode.com/problems/count-complete-tree-nodes/

#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftCount = 1, rightCount = 1;
        TreeNode *leftNode = root->left, *rightNode = root->right;
        while (leftNode)
        {
            leftCount++;
            leftNode = leftNode->left;
        }
        while (rightNode)
        {
            rightCount++;
            rightNode = rightNode->right;
        }

        if (leftCount == rightCount)
        {
            int numNodes = pow(2, leftCount) - 1;
            return numNodes;
        }

        int leftTraverse = countNodes(root->left);
        int rightTraverse = countNodes(root->right);

        return 1 + leftTraverse + rightTraverse;
    }
};

class Solution2
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int count = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            count += n;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return count;
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