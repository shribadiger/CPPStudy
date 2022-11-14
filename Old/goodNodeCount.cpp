/* Program to check the good Node in the tree where leaf node should be maximum
from root path
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, struct TreeNode *l, struct TreeNode *r) : val(x), left(l), right(r) {}
};

void printTree(struct TreeNode *root)
{
    if (root != nullptr)
    {
        cout << "\t" << root->val;
        printTree(root->left);
        printTree(root->right);
    }
}

// utility function to call the recursive function and change the max value of root
int goodNodeCount(struct TreeNode *root, int rootMax)
{
    // base condition to check the last node and return 1 if condition matches
    int counter = 0;
    if (root == nullptr)
    {
        return 0;
    }
    /*if (root->left == nullptr && root->right == nullptr && root->val >= rootMax)
    {
        return 1;
    }*/

    if (root->val >= rootMax)
    {
        rootMax = root->val;
        counter = 1;

        // return 1 + goodNodeCount(root->left, rootMax) + goodNodeCount(root->right, rootMax);
    }
    // else
    //{
    return counter + goodNodeCount(root->left, rootMax) + goodNodeCount(root->right, rootMax);
    //}
}

// Function to check the good node and count the value
int goodNode(struct TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    int rootMax = root->val;
    return goodNodeCount(root, rootMax);
}
int main()
{
    // construction of Tree for Testing the functionality
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->val = 3;
    root->left = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->right = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->left->val = 1;
    root->right->val = 4;
    root->left->left = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->left->left->val = 3;
    root->right->left = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->right->right = (struct TreeNode *)malloc(sizeof(TreeNode));
    root->right->left->val = 1;
    root->right->right->val = 5;
    // printTree(root);

    cout << "\n Result : " << goodNode(root);
    struct TreeNode *root1 = (struct TreeNode *)malloc(sizeof(TreeNode));
    root1->val = 3;
    root1->left = (struct TreeNode *)malloc(sizeof(TreeNode));
    root1->left->val = 3;
    root1->left->left = (struct TreeNode *)malloc(sizeof(TreeNode));
    root1->left->right = (struct TreeNode *)malloc(sizeof(TreeNode));
    root1->left->left->val = 4;
    root1->left->right->val = 2;
    // printTree(root1);

    cout << "\n Result : " << goodNode(root1);
}