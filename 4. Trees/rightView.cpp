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
    vector<int> rightSideView(TreeNode *root)
    {

        if (!root)
            return {};

        vector<int> ans;

        // BFS
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == n - 1)
                    ans.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
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