/* Code to find the maximum path sum in the tree*/
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

int utilityToFindMax(TreeNode *root, int &sum)
{
    if (root == nullptr)
        return 0;

    int leftSum = max(0, utilityToFindMax(root->left, sum));
    int rightSum = max(0, utilityToFindMax(root->right, sum));
    int currSum = root->val + leftSum + rightSum;
    sum = max(sum, currSum);

    return (root->val + max(leftSum, rightSum));
}
int maxPathSum(TreeNode *root)
{
    int sum = INT_MIN;
    utilityToFindMax(root, sum);
    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "\n Result: " << maxPathSum(root);
    root->right->right = new TreeNode(6);
    return 0;
}