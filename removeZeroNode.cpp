/*
 Program to remove the child node which not having any 1 as its value
 if the both the child having zeros then both should be removed from the substree
 */
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *lt, TreeNode *rt) : val(x), left(lt), right(rt) {}
};

TreeNode *prune_tree(TreeNode *root)
{
    if (root) // only in case of valid root
    {
        root->left = prune_tree(root->left);
        root->right = prune_tree(root->right);

        if (root->left || root->right || root->val != 0)
        {
            // we need to keep this node in tree
            return root;
        }
    }
    delete root;
    return nullptr;
}
void print_tree(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << "\t" << root->val;
    print_tree(root->left);
    print_tree(root->right);
}
int main()
{
    // prepare the root node and pass to the executor
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    prune_tree(root);
    print_tree(root);
}