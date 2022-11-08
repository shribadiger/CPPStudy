/* Program to find the duplicate string in the given tree */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

// global data structure to hold the result
std::vector<TreeNode *> result;
std::unordered_map<string, int> stringNodes;

string getString(TreeNode *root)
{
    if (root == nullptr)
        return ""; // if the root is empty,  leaf node is reached
    std::string leftStr = getString(root->left);
    std::string rightStr = getString(root->right);
    std::string input = "(" + leftStr + to_string(root->val) + rightStr + ")"; // preparaing left+root+right sting to check
    if (stringNodes[input] != -1)
        stringNodes[input]++;
    if (stringNodes[input] > 1)
    {
        result.push_back(root);
        stringNodes[input] = -1;
    }
    return input;
}

std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    getString(root);
    return result;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    vector<TreeNode *> result = findDuplicateSubtrees(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\t" << result[i]->val;
    }
}