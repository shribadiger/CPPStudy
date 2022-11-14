/* Code tp flat the given tree leetcode problem*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
TreeNode *temp = nullptr;
void dfs(TreeNode *oldRoot)
{
    if (oldRoot == nullptr)
        return;
    // logic to check root left and call the same
    dfs(oldRoot->right);
    dfs(oldRoot->left);
    oldRoot->left = nullptr;
    oldRoot->right = temp;
    temp = oldRoot;
}

void printTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << "\t" << root->val;
    printTree(root->right);
}
void flatten(TreeNode *root)
{
    if (root == nullptr) // base condition to check the nullptr
        return;
    TreeNode *newRoot = nullptr;
    dfs(root);
    printTree(root);
}
int main()
{
    // creating the Tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    flatten(root);

    // printTree(root);
}