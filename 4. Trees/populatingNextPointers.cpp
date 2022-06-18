#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right, *next;
    TreeNode(int val)
    {
        this->val = val;
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

class Solution
{
public:
    TreeNode *populateNext(TreeNode *root)
    {
        if (!root)
            return root;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (i != sz - 1)
                    node->next = q.front();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return root;
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