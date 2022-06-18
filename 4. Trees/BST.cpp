#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        this->data = data;
    }
};

TreeNode *insertIntoBST(TreeNode *root, int value)
{
    if (root == NULL)
    {
        cout << "new root creation" << endl;
        root = new TreeNode(value);
        cout << "new root created" << endl;
        return root;
    }
    
    if (value < root->data)
    {
        cout << "adding data to left" << endl;
        root->left = insertIntoBST(root->left, value);
        cout << "data added to left" << endl;
    }
    else
    {
        cout << "adding data to right" << endl;
        root->right = insertIntoBST(root->right, value);
        cout << "data added to right" << endl;
    }

    return root;
}

void takeInput(TreeNode *&root)
{
    int value;
    cin >> value;

    while (value != -1)
    {
        cout << "taking input..." << endl;
        root = insertIntoBST(root, value);
        cout << "data added to tree" << endl;
        cout << root->data << endl;
        cin >> value;
    }
}

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    TreeNode *root = NULL;

    cout << "Enter Data for BST\n";
    takeInput(root);
    cout << endl;
    inorder(root);

    return 0;
}