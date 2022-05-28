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

int makeSum(TreeNode *root)
{
    if (!root)
        return 0;

    return root->val += makeSum(root->left) + makeSum(root->right);
}

int countSum(TreeNode *root, int target)
{
    if (!root)
        return 0;

    int k = (root->val == target) ? 1 : 0;

    return k + countSum(root->left, target) + countSum(root->right, target);
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    TreeNode *root;
    root = createBTree();
    inOrder(root);
    cout << endl;
    makeSum(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    cout << countSum(root, 5) << endl;

    return 0;
}