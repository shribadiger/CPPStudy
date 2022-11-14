#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};
bool isisTargetSumInTree(TreeNode *root, int targetSum)
{
    bool isPath = false;
    dfs(root, targetSum, isPath);
    return isPath;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    if (isTargetSumInTree(root, 9))
    {
        cout << "\n Done";
    }
    else
    {
        cout << "\n Failed";
    }
}