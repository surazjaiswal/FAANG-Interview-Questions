#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

bool pathSum(Node *root, int target)
{
    return checkPathSum(root, 0, target);
}

bool checkPathSum(Node *root, int sum, int target)
{
    if (!root)
        return false;

    sum += root->val;

    if (sum == target && (!root->left && !root->right))
        return true;

    if (sum == target && (!root->left || !root->right))
        return false;

    bool leftCheck = checkPathSum(root->left, sum, target);
    bool rightCheck = checkPathSum(root->right, sum, target);

    return leftCheck || rightCheck;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    return 0;
}