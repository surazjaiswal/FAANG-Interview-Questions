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

bool isSymmetric(Node *root)
{
    if (!root)
        return false;

    return checkSymmetric(root->left, root->right);
}

bool checkSymmetric(Node *leftNode, Node *rightNode)
{
    if (!leftNode && !rightNode)
        return true;

    if (!leftNode || !rightNode)
        return false;

    if (leftNode->val != rightNode->val)
        return false;

    bool leftSym = checkSymmetric(leftNode->left, rightNode->right);
    bool rightSym = checkSymmetric(leftNode->right, rightNode->left);

    return leftSym || rightSym;
}

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    return 0;
}