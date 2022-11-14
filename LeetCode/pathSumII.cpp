/* Finding the path sum problem*/
#include <iostream>
#include <vector>
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
vector<vector<int>> result;
// implemenation of below DFS function in recursive order
void dfs(TreeNode *root, int targetSum, vector<int> path)
{
    // checking the root condition
    if (root == nullptr)
        return;
    path.push_back(root->val);

    targetSum = targetSum - root->val;
    // checking the leaf node  conditon
    if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        result.push_back(path);
    dfs(root->left, targetSum, path);
    dfs(root->right, targetSum, path);
    path.pop_back();
}
//  global variable to return

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> path;
    dfs(root, targetSum, path);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(2);
    root->right->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(2);

    // calling the printTree
    vector<vector<int>> res = pathSum(root, 6);

    for (int i = 0; i < res.size(); i++)
    {
        for (auto val : res[i])
        {
            cout << "\t" << val;
        }
        cout << "\n";
    }
}